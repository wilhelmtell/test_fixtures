#ifndef FIXTURES_TEMPORARY_DIRECTORY_TCC_
#define FIXTURES_TEMPORARY_DIRECTORY_TCC_

#include <string>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>

namespace fixtures {
temporary_directory::temporary_directory(std::string const& name)
: temp_path(boost::filesystem::temp_directory_path() / name)
{
    boost::filesystem::create_directories(temp_path);
}

temporary_directory::temporary_directory()
: temp_path(boost::filesystem::temp_directory_path() / boost::filesystem::unique_path())
{
    boost::filesystem::create_directories(temp_path);
}

temporary_directory::~temporary_directory()
{
    boost::system::error_code err;
    boost::filesystem::remove_all(temp_path, err);
    if( err ) {
        std::cerr
            << "WARNING:failed to remove temporary directory "
            << path().string() << '\n';
    }
}

const boost::filesystem::path& temporary_directory::path() const
{
    return temp_path;
}
}  // namespace fixtures

#endif  // FIXTURES_TEMPORARY_DIRECTORY_TCC_
