#ifndef FIXTURES_TEMPORARY_FILE_TCC_
#define FIXTURES_TEMPORARY_FILE_TCC_

#include <string>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

namespace fixtures {
temporary_file::temporary_file(std::string const& name)
: file_path(boost::filesystem::temp_directory_path() / name)
{
    boost::filesystem::create_directories(file_path);
}

temporary_file::temporary_file()
: file_path(boost::filesystem::temp_directory_path() / boost::filesystem::unique_path())
{
    boost::filesystem::create_directories(file_path);
}

temporary_file::~temporary_file()
{
    boost::system::error_code err;
    boost::filesystem::remove_all(file_path, err);
    if( err ) {
        std::cerr
            << "WARNING:failed to remove temporary file "
            << path().string() << '\n';
    }
}

const boost::filesystem::path& temporary_file::path() const
{
    return file_path;
}
}  // namespace fixtures

#endif  // FIXTURES_TEMPORARY_FILE_TCC_
