#ifndef FIXTURES_PUSHD_TEMPORARY_DIRECTORY_HH_
#define FIXTURES_PUSHD_TEMPORARY_DIRECTORY_HH_

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include "temporary_directory.hh"
#include <string>

namespace fixtures {
struct pushd_temporary_directory {
    pushd_temporary_directory(std::string const& name)
    : temp_dir(name)
    , original_path(boost::filesystem::current_path())
    {
        boost::filesystem::current_path(path());
    }

    pushd_temporary_directory()
    : temp_dir()
    , original_path(boost::filesystem::current_path())
    {
        boost::filesystem::current_path(path());
    }

    ~pushd_temporary_directory()
    {
        boost::system::error_code err;
        boost::filesystem::current_path(original_path, err);
        if( err ) {
            std::cerr
                << "WARNING:failed to change current directory back to "
                << original_path.string() << '\n';
        }
    }

    pushd_temporary_directory(pushd_temporary_directory const&) = delete;
    pushd_temporary_directory& operator=(pushd_temporary_directory const&) = delete;

    const boost::filesystem::path& path() const { return temp_dir.path(); }

private:
    temporary_directory temp_dir;
    boost::filesystem::path original_path;
};
}  // namespace fixtures

#endif  // FIXTURES_PUSHD_TEMPORARY_DIRECTORY_HH_
