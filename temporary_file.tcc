#ifndef FIXTURES_TEMPORARY_FILE_TCC_
#define FIXTURES_TEMPORARY_FILE_TCC_

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <utility>

namespace fixtures {
temporary_file::temporary_file(boost::filesystem::path p)
: file_path(std::move(p))
{
    boost::filesystem::create_directories(file_path);
}

temporary_file::temporary_file()
: temporary_file(boost::filesystem::temp_directory_path() / boost::filesystem::unique_path())
{
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

boost::filesystem::path temporary_file::path() const
{
    return file_path;
}
}  // namespace fixtures

#endif  // FIXTURES_TEMPORARY_FILE_TCC_
