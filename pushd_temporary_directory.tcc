#ifndef FIX_PUSHD_TEMPORARY_DIRECTORY_TCC_
#define FIX_PUSHD_TEMPORARY_DIRECTORY_TCC_

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include <utility>

namespace fix {
pushd_temporary_directory::pushd_temporary_directory(boost::filesystem::path p)
: temp_dir(std::move(p))
, original_path(boost::filesystem::current_path())
{
    boost::filesystem::current_path(path());
}

pushd_temporary_directory::pushd_temporary_directory()
: temp_dir()
, original_path(boost::filesystem::current_path())
{
    boost::filesystem::current_path(path());
}

pushd_temporary_directory::~pushd_temporary_directory()
{
    boost::system::error_code err;
    boost::filesystem::current_path(original_path, err);
}

pushd_temporary_directory::pushd_temporary_directory(pushd_temporary_directory&& rhs)
: temp_dir(std::move(rhs.temp_dir))
, original_path(std::move(rhs.original_path))
{
}

pushd_temporary_directory& pushd_temporary_directory::operator=(pushd_temporary_directory&&)
{
    using std::swap;
    swap(temp_dir, rhs.temp_dir);
    swap(original_path, rhs.original_path);
}

boost::filesystem::path pushd_temporary_directory::path() const
{
    return temp_dir.path();
}
}  // namespace fix

#endif  // FIX_PUSHD_TEMPORARY_DIRECTORY_TCC_
