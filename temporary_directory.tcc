#ifndef FIX_TEMPORARY_DIRECTORY_TCC_
#define FIX_TEMPORARY_DIRECTORY_TCC_

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include <utility>

namespace fix {
temporary_directory::temporary_directory(boost::filesystem::path p)
: temp_path(std::move(p))
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
}

temporary_directory::temporary_directory(temporary_directory&& rhs)
: temp_path(std::move(rhs.temp_path)
{
}

temporary_directory& temporary_directory::operator=(temporary_directory&& rhs)
{
    using std::swap;
    swap(temp_path, rhs.temp_path);
}

boost::filesystem::path temporary_directory::path() const
{
    return temp_path;
}
}  // namespace fix

#endif  // FIX_TEMPORARY_DIRECTORY_TCC_
