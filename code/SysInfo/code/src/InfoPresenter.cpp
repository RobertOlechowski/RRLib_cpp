#include "SysInfo/InfoPresenter.h"
#include "SysInfo/CompilerInfo.h"
#include "SysInfo/EnumToString.h"
#include "SysInfo/LibsInfo.h"
#include "SysInfo/SystemInfo.h"

#include <Others/StlFlagsGuard.h>
#include <Assert/Asserts.h>

#include <expat.h>
#include <iostream>

namespace RRLibs::SysInfo {

using namespace std;

static constexpr uint pad_size_1 = 14;
static constexpr uint pad_size_2 = 8;

InfoPresenter::InfoPresenter()
        : m_compiler_info(new CompilerInfo()), m_libs_info(new LibsInfo()), m_system_info(new SystemInfo()) {}

InfoPresenter::~InfoPresenter() = default;

//=================================================================

void InfoPresenter::show(const initializer_list<const Element>& elements, bool skip_invalid) const {
    Common::StlFlagsGuard guard;
    for (const auto& item : elements) {
        show_element(item, skip_invalid);
    }
    std::cout << std::endl;
}

void InfoPresenter::show_element(Element element, bool skip_invalid) const {
    switch (element) {
        case Element::Compiler:
            return show_compiler_info(skip_invalid);
        case Element::LibC:
            return show_libc_info(skip_invalid);
        case Element::LibCpp:
            return show_libcpp_info(skip_invalid);
        case Element::Lib_OpenCV:
            return show_lib_opencv(skip_invalid);
        case Element::Lib_Boost:
            return show_lib_boost(skip_invalid);
        case Element::Lib_MMal:
            return show_lib_mmal(skip_invalid);
        case Element::Lib_vcos:
            return show_lib_vcos(skip_invalid);
        case Element::OS_Type:
            return show_os_type(skip_invalid);
        case Element::OS_Release:
            return show_os_release(skip_invalid);
        case Element::App_mode:
            return show_app_mode(skip_invalid);
        case Element::App_dir:
            return show_app_dir(skip_invalid);
        default:
            RRLibs::assert_fail(__func__);
    }
}

void InfoPresenter::show_compiler_info(bool skip_invalid) const {
    const auto name = to_text(m_compiler_info->get_compiler());
    const auto ver = m_compiler_info->get_compiler_version().to_string();
    cout.width(pad_size_1);
    cout << left << name << ": ";
    cout.width(pad_size_2);
    cout << ver;
    cout << "\t" << "C++ : " << to_text(m_compiler_info->get_cpp_version());
    std::cout << std::endl;
}

void InfoPresenter::show_lib_opencv(bool skip_invalid) const {
    Version::Version version = m_libs_info->get_openCV();
    if(skip_invalid && !version.is_valid())
        return;

    cout.width(pad_size_1);
    std::cout << "OpenCV Ver " << ": ";
    cout.width(pad_size_2);
    std::cout << version.to_string();
    std::cout << "\t" << "OPENCV2 : " << m_libs_info->is_opencv2();
    std::cout << std::endl;
}

void InfoPresenter::show_lib_boost(bool skip_invalid) const {
    Version::Version version = m_libs_info->get_boost_version();
    if(skip_invalid && !version.is_valid())
        return;

    cout.width(pad_size_1);
    std::cout << "Boost Ver " << ": ";
    cout.width(pad_size_2);
    std::cout << version.to_string();
    std::cout << std::endl;
}

void InfoPresenter::show_os_type(bool skip_invalid) const {
    const auto os_name = to_text(m_system_info->get_os_type());
    cout.width(pad_size_1);
    std::cout << "OS type " << ": ";
    cout.width(pad_size_2);
    std::cout << os_name << "\t" << m_system_info->get_machine();
    //m_system_info->get_sys_name()
    std::cout << std::endl;
}

void InfoPresenter::show_os_release(bool skip_invalid) const {
    cout.width(pad_size_1);
    std::cout << "Release " << ": ";
    cout.width(pad_size_2);
    std::cout << m_system_info->get_release() << "\t" << m_system_info->get_version();
    std::cout << std::endl;
}

void InfoPresenter::show_app_mode(bool skip_invalid) const {
    cout.width(pad_size_1);
    std::cout << "App mode " << ": ";
    std::cout << m_system_info->get_bit_mode() << " bit\t";
    std::cout << to_text(m_compiler_info->get_compilation_mode());
    std::cout << std::endl;
}

void InfoPresenter::show_app_dir(bool skip_invalid) const {
    cout.width(pad_size_1);
    std::cout << "Current dir " << ": ";
    cout.width(pad_size_2);
    std::cout << m_system_info->get_current_dir();
    std::cout << std::endl;
}

void InfoPresenter::show_libc_info(bool skip_invalid) const {
    Version::Version version = m_libs_info->get_libc_version();
    cout.width(pad_size_1);
    std::cout << "LibC " << ": ";
    cout.width(pad_size_2);
    std::cout << version.to_string();
    std::cout << "\t" << version.get_suffix();
    std::cout << std::endl;
}

void InfoPresenter::show_libcpp_info(bool skip_invalid) const {
    Version::Version version = m_libs_info->get_libcpp_version();
    cout.width(pad_size_1);
    std::cout << "LibCpp " << ": ";
    cout.width(pad_size_2);
    std::cout << version.to_string();
    std::cout << "\t" << version.get_suffix();
    std::cout << std::endl;
}

void InfoPresenter::show_lib_mmal(bool skip_invalid) const {
    Version::Version version = m_libs_info->get_mmal_version();
    if(skip_invalid && !version.is_valid())
        return;

    cout.width(pad_size_1);
    std::cout << "MMal Ver " << ": ";
    cout.width(pad_size_2);
    std::cout << version.to_string();
    std::cout << "\tMinimum : " << m_libs_info->get_mmal_minimum();
    std::cout << std::endl;
}

void InfoPresenter::show_lib_vcos(bool skip_invalid) const {
    Version::Version version = m_libs_info->get_vcos_version();
    if(skip_invalid && !version.is_valid())
        return;

    cout.width(pad_size_1);
    std::cout << "Vcos Ver " << ": ";
    cout.width(pad_size_2);
    std::cout << version.to_string();
    std::cout << std::endl;
}

}