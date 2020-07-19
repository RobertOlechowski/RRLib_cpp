#pragma once

#include <Common/NonCopyableNotMovable.h>

#include <initializer_list>
#include <memory>

namespace RRLibs::SysInfo {

class CompilerInfo;

class LibsInfo;

class SystemInfo;

class InfoPresenter : public Common::NonCopyableNotMovable {
public:
    enum class Element {
        Compiler,
        LibC,
        LibCpp,
        Lib_OpenCV,
        Lib_Boost,
        Lib_MMal,
        Lib_vcos,
        OS_Type,
        OS_Release,
        App_mode,
        App_dir,

    };
    constexpr static const std::initializer_list<const Element>& All = {
            Element::Compiler,
            Element::LibC,
            Element::LibCpp,
            Element::Lib_OpenCV,
            Element::Lib_Boost,
            Element::Lib_MMal,
            Element::Lib_vcos,
            Element::OS_Type,
            Element::OS_Release,
            Element::App_mode,
            Element::App_dir,
    };


    InfoPresenter();

    ~InfoPresenter() override;

    void show(const std::initializer_list<const Element>& elements, bool skip_invalid) const;

private:
    std::unique_ptr<CompilerInfo> m_compiler_info;
    std::unique_ptr<LibsInfo> m_libs_info;
    std::unique_ptr<SystemInfo> m_system_info;

    void show_element(Element element, bool skip_invalid) const;

    void show_compiler_info(bool skip_invalid) const;

    void show_libc_info(bool skip_invalid) const;

    void show_libcpp_info(bool skip_invalid) const;

    void show_lib_opencv(bool skip_invalid) const;

    void show_lib_boost(bool skip_invalid) const;

    void show_lib_mmal(bool skip_invalid) const;

    void show_lib_vcos(bool skip_invalid) const;

    void show_os_type(bool skip_invalid) const;

    void show_os_release(bool skip_invalid) const;

    void show_app_mode(bool skip_invalid) const;

    void show_app_dir(bool skip_invalid) const;

};

}


