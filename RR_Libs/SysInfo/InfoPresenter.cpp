#include "InfoPresenter.h"
#include "CompilerInfo.h"
#include "EnumToString.h"
#include "LibsInfo.h"
#include "SystemInfo.h"
#include <iostream>
#include <Common/StlFlagsGuard.h>
#include <Common/Asserts.h>
#include <expat.h>

namespace RRLibs::SysInfo {

using namespace std;

static constexpr uint pad_size_1 = 14;
static constexpr uint pad_size_2 = 8;

InfoPresenter::InfoPresenter()
        : m_compiler_info(new CompilerInfo()), m_libs_info(new LibsInfo()), m_system_info(new SystemInfo()) {}

void InfoPresenter::show(const initializer_list<const Element>& elements) const {
    Common::StlFlagsGuard guard;
    for (const auto& item : elements) {
        show_element(item);
    }
    std::cout << std::endl;
}

InfoPresenter::~InfoPresenter() {}

void InfoPresenter::show_element(Element element) const {
    switch (element) {
        case Element::Compiler:
            return show_compiler_info();
        case Element::LibC:
            return show_libc_info();
        case Element::Lib_OpenCV:
            return show_lib_opencv();
        case Element::Lib_Boost:
            return show_lib_boost();
        case Element::Lib_MMal:
            return show_lib_mmal();
        case Element::Lib_vcos:
            return show_lib_vcos();
        case Element::OS_Type:
            return show_os_type();
        case Element::OS_Release:
            return show_os_release();
        case Element::App_mode:
            return show_app_mode();
        case Element::App_dir:
            return show_app_dir();
        default:
            RRLibs::assert_fail(__func__);
    }
}

void InfoPresenter::show_compiler_info() const {
    const auto name = to_text(m_compiler_info->get_compiler());
    const auto ver = m_compiler_info->get_compiler_version().to_string();
    cout.width(pad_size_1);
    cout << left << name << ": ";
    cout.width(pad_size_2);
    cout << ver;
    cout << "\t" << "C++ : " << to_text(m_compiler_info->get_cpp_version());
    std::cout << std::endl;
}

void InfoPresenter::show_lib_opencv() const {
    cout.width(pad_size_1);
    std::cout << "OpenCV Ver " << ": ";
    cout.width(pad_size_2);
    std::cout << m_libs_info->get_openCV().to_string();
    std::cout << "\t" << "OPENCV2 : " << m_libs_info->is_opencv2();
    std::cout << std::endl;
}

void InfoPresenter::show_lib_boost() const {
    cout.width(pad_size_1);
    std::cout << "Boost Ver " << ": ";
    cout.width(pad_size_2);
    std::cout << m_libs_info->get_boost_version().to_string();
    std::cout << std::endl;
}

void InfoPresenter::show_os_type() const {
    const auto os_name = to_text(m_system_info->get_os_type());
    cout.width(pad_size_1);
    std::cout << "OS type " << ": ";
    cout.width(pad_size_2);
    std::cout << os_name << "\t" << m_system_info->get_machine();
    //m_system_info->get_sys_name()
    std::cout << std::endl;
}

void InfoPresenter::show_os_release() const {
    cout.width(pad_size_1);
    std::cout << "Release " << ": ";
    cout.width(pad_size_2);
    std::cout << m_system_info->get_release() << "\t" << m_system_info->get_version();
    std::cout << std::endl;
}

void InfoPresenter::show_app_mode() const {
    cout.width(pad_size_1);
    std::cout << "App mode " << ": ";
    std::cout << m_system_info->get_bit_mode() << " bit\t";
    std::cout << to_text(m_compiler_info->get_compilation_mode());
    std::cout << std::endl;
}

void InfoPresenter::show_app_dir() const {
    cout.width(pad_size_1);
    std::cout << "Current dir " << ": ";
    cout.width(pad_size_2);
    std::cout << m_system_info->get_current_dir();
    std::cout << std::endl;
}

void InfoPresenter::show_libc_info() const {
    cout.width(pad_size_1);
    std::cout << "LibC Ver " << ": ";
    cout.width(pad_size_2);
    std::cout << m_libs_info->get_libc_version().to_string();
    std::cout << "\t" << m_libs_info->get_libc_version().get_suffix();
    std::cout << std::endl;
}

void InfoPresenter::show_lib_mmal() const {
    cout.width(pad_size_1);
    std::cout << "MMal Ver " << ": ";
    cout.width(pad_size_2);
    std::cout << m_libs_info->get_mmal_version().to_string();
    std::cout << "\tMinimum : " << m_libs_info->get_mmal_minimum();
    std::cout << std::endl;
}

void InfoPresenter::show_lib_vcos() const {
    cout.width(pad_size_1);
    std::cout << "Vcos Ver " << ": ";
    cout.width(pad_size_2);
    std::cout << m_libs_info->get_vcos_version().to_string();
    std::cout << std::endl;
}

}