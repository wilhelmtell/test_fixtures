#ifndef FIX_PUSHD_TEMPORARY_DIRECTORY_HH_
#define FIX_PUSHD_TEMPORARY_DIRECTORY_HH_

#include <boost/filesystem/path.hpp>
#include "temporary_directory.hh"

namespace fix {
struct pushd_temporary_directory {
    explicit pushd_temporary_directory(boost::filesystem::path p);
    pushd_temporary_directory();
    ~pushd_temporary_directory();
    pushd_temporary_directory(pushd_temporary_directory const&) = delete;
    pushd_temporary_directory& operator=(pushd_temporary_directory const&) = delete;
    pushd_temporary_directory(pushd_temporary_directory&& rhs) = default;
    pushd_temporary_directory& operator=(pushd_temporary_directory&&) = default;

    boost::filesystem::path path() const;

private:
    temporary_directory temp_dir;
    boost::filesystem::path original_path;
};

void swap(pushd_temporary_directory& lhs, pushd_temporary_directory& rhs);
}  // namespace fix

#include "pushd_temporary_directory.tcc"

#endif  // FIX_PUSHD_TEMPORARY_DIRECTORY_HH_
