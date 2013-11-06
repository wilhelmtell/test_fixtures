#ifndef FIXTURES_TEMPORARY_FILE_TCC_
#define FIXTURES_TEMPORARY_FILE_TCC_

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <utility>
#include <fstream>

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
}

boost::filesystem::path temporary_file::path() const
{
    return file_path;
}

template<typename T>
temporary_file& operator<<(temporary_file& out, T const& value)
{
    std::ofstream file(out.path().string());
    file << value;
    return out;
}

template<typename T>
temporary_file& operator>>(temporary_file& in, T& value)
{
    std::ifstream file(in.path().string());
    file >> value;
    return in;
}
}  // namespace fixtures

#endif  // FIXTURES_TEMPORARY_FILE_TCC_
