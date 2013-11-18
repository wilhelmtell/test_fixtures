#ifndef FIX_TEMPORARY_FILE_TCC_
#define FIX_TEMPORARY_FILE_TCC_

#include "temporary_file.hh"
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <utility>
#include <fstream>
#include <cassert>

namespace fix {
inline temporary_file::temporary_file(boost::filesystem::path p)
: file_path(std::move(p))
{
    assert( ! boost::filesystem::exists(p) );
    std::ofstream { p.string() };
    assert( boost::filesystem::exists(p) );
}

inline temporary_file::temporary_file()
: temporary_file(boost::filesystem::temp_directory_path() / boost::filesystem::unique_path())
{
}

inline temporary_file::~temporary_file()
{
    boost::system::error_code err;
    boost::filesystem::remove_all(file_path, err);
}

inline boost::filesystem::path temporary_file::path() const
{
    return file_path;
}

template<typename T>
temporary_file& operator<<(temporary_file& out, T const& value)
{
    std::ofstream file(out.path().string());
    file << value;
    return out;
}

template<typename T>
temporary_file& operator>>(temporary_file& in, T& value)
{
    std::ifstream file(in.path().string());
    file >> value;
    return in;
}
}  // namespace fix

#endif  // FIX_TEMPORARY_FILE_TCC_
