#ifndef TEMPORARY_DIRECTORY_HH_
#define TEMPORARY_DIRECTORY_HH_

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include <string>

namespace fixtures {
struct temporary_directory {
    temporary_directory(const std::string& name)
    : temp_path(boost::filesystem::temp_directory_path() / name)
    {
        boost::filesystem::create_directories(temp_path);
    }

    temporary_directory()
    : temp_path(boost::filesystem::temp_directory_path() / boost::filesystem::unique_path())
    {
        boost::filesystem::create_directories(temp_path);
    }

    ~temporary_directory()
    {
        boost::system::error_code err;
        boost::filesystem::remove_all(temp_path, err);
        if( err ) {
            std::cerr
                << "WARNING:failed to remove temporary directory "
                << path().string() << '\n';
        }
    }

    temporary_directory(temporary_directory const&) = delete;
    temporary_directory& operator=(temporary_directory const&) = delete;

    const boost::filesystem::path& path() const { return temp_path; }

private:
    boost::filesystem::path temp_path;
};
}  // namespace fixtures

#endif  // TEMPORARY_DIRECTORY_HH_
