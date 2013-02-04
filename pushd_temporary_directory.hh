#ifndef FIXTURES_PUSHD_TEMPORARY_DIRECTORY_HH_
#define FIXTURES_PUSHD_TEMPORARY_DIRECTORY_HH_

#include <boost/filesystem/path.hpp>
#include "temporary_directory.hh"
#include <string>

namespace fixtures {
struct pushd_temporary_directory {
    pushd_temporary_directory(std::string const& name);
    pushd_temporary_directory();
    ~pushd_temporary_directory();
    pushd_temporary_directory(pushd_temporary_directory const&) = delete;
    pushd_temporary_directory& operator=(pushd_temporary_directory const&) = delete;

    const boost::filesystem::path& path() const;

private:
    temporary_directory temp_dir;
    boost::filesystem::path original_path;
};
}  // namespace fixtures

#include "pushd_temporary_directory.tcc"

#endif  // FIXTURES_PUSHD_TEMPORARY_DIRECTORY_HH_
