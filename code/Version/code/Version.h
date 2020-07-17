#pragma once

#include <Common/Types.h>
#include <memory>

namespace RRLibs::Version {

class Version;

using VersionPtr = std::unique_ptr<Version>;

class Version {
public:
    static Version ERR();

    explicit Version();

    explicit Version(const std::string& str, const std::string suffix = "");

    explicit Version(int p1, int p2 = -1, int p3 = -1, int p4 = -1);


    ~Version() = default;

    std::string to_string(bool add_suffix = false) const;

    const std::string& get_suffix() const { return m_suffix; }

private:
    std::string m_suffix;
    bool has_error = false;
    int m_major = -1;
    int m_minor = -1;
    int m_revision = -1;
    int m_build = -1;

    void __to_string(std::ostringstream& arg) const;
};

}


