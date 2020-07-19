#pragma once

#include <memory>
#include <iostream>

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

public:
    const std::string& get_suffix() const { return m_suffix; }
    bool is_valid() const;

public:
    std::string to_string(bool add_suffix = false) const;
    void to_string(std::ostream& out) const;
    friend std::ostream& operator<< (std::ostream& out, const Version& point);

private:
    std::string m_suffix;
    bool has_error = false;
    int m_major = -1;
    int m_minor = -1;
    int m_revision = -1;
    int m_build = -1;

private:

};

}


