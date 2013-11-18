#ifndef FIX_TEMPORARY_DIRECTORY_HH_
#define FIX_TEMPORARY_DIRECTORY_HH_

#include "temporary_file.hh"
#include <boost/filesystem/path.hpp>
#include <vector>

namespace fix {
struct temporary_directory {
    explicit temporary_directory(boost::filesystem::path p);
    temporary_directory();
    ~temporary_directory();
    temporary_directory(temporary_directory const&) = delete;
    temporary_directory& operator=(temporary_directory const&) = delete;
    temporary_directory(temporary_directory&& rhs) = default;
    temporary_directory& operator=(temporary_directory&& rhs) = default;

    boost::filesystem::path path() const;

private:
    boost::filesystem::path temp_path;
    std::vector<temporary_file> tempfiles;
};

template<typename T>
temporary_directory& operator<<(temporary_directory& out, temporary_file file);
}  // namespace fix

#include "temporary_directory.tcc"

#endif  // FIX_TEMPORARY_DIRECTORY_HH_
