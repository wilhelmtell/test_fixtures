#ifndef FIX_PUSHD_TEMPORARY_DIRECTORY_TCC_
#define FIX_PUSHD_TEMPORARY_DIRECTORY_TCC_

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
: temp_dir()
, original_path(boost::filesystem::current_path())
{
    boost::filesystem::current_path(path());
}

inline pushd_temporary_directory::~pushd_temporary_directory()
{
    boost::system::error_code err;
    boost::filesystem::current_path(original_path, err);
}

inline void swap(pushd_temporary_directory& lhs, pushd_temporary_directory& rhs)
{
    pushd_temporary_directory temporary(std::move(lhs));
    lhs = std::move(rhs);
    rhs = std::move(temporary);
}

inline boost::filesystem::path pushd_temporary_directory::path() const
{
    return temp_dir.path();
}
}  // namespace fix

#endif  // FIX_PUSHD_TEMPORARY_DIRECTORY_TCC_
