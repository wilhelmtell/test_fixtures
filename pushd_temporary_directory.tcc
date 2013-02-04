#ifndef FIXTURES_PUSHD_TEMPORARY_DIRECTORY_TCC_
#define FIXTURES_PUSHD_TEMPORARY_DIRECTORY_TCC_

#include <string>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>

namespace fixtures {
pushd_temporary_directory::pushd_temporary_directory(std::string const& name)
: temp_dir(name)
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
    if( err ) {
        std::cerr
            << "WARNING:failed to change current directory back to "
            << original_path.string() << '\n';
    }
}

boost::filesystem::path path() const
{
    return temp_dir.path();
}
}  // namespace fixtures

#endif  // FIXTURES_PUSHD_TEMPORARY_DIRECTORY_TCC_
