#ifndef FIX_PUSHD_TEMPORARY_DIRECTORY_TCC_
#define FIX_PUSHD_TEMPORARY_DIRECTORY_TCC_

#include "pushd_temporary_directory.hh"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include <utility>

namespace fix {
inline pushd_temporary_directory::pushd_temporary_directory(boost::filesystem::path p)
: temp_dir(std::move(p))
, original_path(boost::filesystem::current_path())
{
    boost::filesystem::current_path(path());
}

inline pushd_temporary_directory::pushd_temporary_directory()
: pushd_temporary_directory(boost::filesystem::temp_directory_path() / boost::filesystem::unique_path())
{
}

inline pushd_temporary_directory::~pushd_temporary_directory()
{
    boost::system::error_code err;
    boost::filesystem::current_path(original_path, err);
}

inline boost::filesystem::path pushd_temporary_directory::path() const
{
    return temp_dir.path();
}
}  // namespace fix

#endif  // FIX_PUSHD_TEMPORARY_DIRECTORY_TCC_
