#ifndef FIX_TEMPORARY_DIRECTORY_TCC_
#define FIX_TEMPORARY_DIRECTORY_TCC_

#include "temporary_directory.hh"
#include "temporary_file.hh"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include <utility>
#include <vector>

namespace fix {
inline temporary_directory::temporary_directory(boost::filesystem::path p)
: temp_path(std::move(p))
, tempfiles()
{
    boost::filesystem::create_directories(temp_path);
}

inline temporary_directory::temporary_directory()
: temporary_directory(boost::filesystem::temp_directory_path() / boost::filesystem::unique_path())
{
    boost::filesystem::create_directories(temp_path);
}

inline temporary_directory::~temporary_directory()
{
    boost::system::error_code err;
    boost::filesystem::remove_all(temp_path, err);
}

inline boost::filesystem::path temporary_directory::path() const
{
    return temp_path;
}

template<typename T>
temporary_directory& operator<<(temporary_directory& out, temporary_file file)
{
    tempfiles.push_back(std::move(file));
    return *this;
}
}  // namespace fix

#endif  // FIX_TEMPORARY_DIRECTORY_TCC_
