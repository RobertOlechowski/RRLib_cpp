#include "Version/Version.h"
#include <Others/Converter.h>

#include <sstream>
#include <iostream>

namespace RRLibs::Version {


Version::Version(const std::string& s, const std::string suffix)
        : m_suffix(suffix) {
    static const std::string delimiter = ".";

    const std::array<int*, 4> arr = {&m_major, &m_minor, &m_revision, &m_build};
    for (auto item : arr)
        *item = -1;

    size_t prev_pos = 0;
    try {
        for (int i = 0; i < 4; ++i) {
            const size_t pos = s.find(delimiter, prev_pos);
            const size_t size = pos != std::string::npos ? pos - prev_pos : s.length() - prev_pos;
            std::string token = s.substr(prev_pos, size);
            const int val = Common::Converter::parse_int(token);

            *arr[i] = val;
            if (pos == std::string::npos)
                break;
            prev_pos = pos + 1;
        }
        has_error = false;
    } catch (...) {
        has_error = true;
    }
}

Version::Version() {
    has_error = false;
}

Version::Version(int p1, int p2, int p3, int p4) {
    m_major = p1;
    m_minor = p2;
    m_revision = p3;
    m_build = p4;
}



Version Version::ERR() {
    Version ret;
    ret.has_error = true;
    return ret;
}

//========================================================

bool Version::is_valid() const {
    if (has_error) {
        return false;
    }

    if (m_major < 0) {
        return false;
    }

    return true;
}

//========================================================

std::string Version::to_string(bool add_suffix) const {
    std::ostringstream stringStream;
    to_string(stringStream);

    if (!m_suffix.empty() && add_suffix)
        stringStream << "  " << m_suffix;

    return stringStream.str();
}

void Version::to_string(std::ostream& out) const {
    if (has_error) {
        out << "ERROR";
        return;
    }

    if (m_major < 0) {
        out << "----";
        return;
    }

    out << m_major;

    if (m_minor < 0)
        return;
    out << "." << m_minor;

    if (m_revision < 0)
        return;
    out << "." << m_revision;

    if (m_build < 0)
        return;
    out << "." << m_build;
}

std::ostream& operator<<(std::ostream& out, const Version& point) {
    point.to_string(out);
    return out;
}


}