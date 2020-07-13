#pragma once

#include "Common/NonCopyableNotMovable.h"

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

    void show(const std::initializer_list<const Element>& elements) const;

private:
    std::unique_ptr<CompilerInfo> m_compiler_info;
    std::unique_ptr<LibsInfo> m_libs_info;
    std::unique_ptr<SystemInfo> m_system_info;

    void show_element(Element element) const;

    void show_compiler_info() const;

    void show_libc_info() const;

    void show_lib_opencv() const;

    void show_lib_boost() const;

    void show_lib_mmal() const;

    void show_lib_vcos() const;

    void show_os_type() const;

    void show_os_release() const;

    void show_app_mode() const;

    void show_app_dir() const;

};

}


