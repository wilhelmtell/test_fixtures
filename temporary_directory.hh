#ifndef FIX_TEMPORARY_DIRECTORY_HH_
#define FIX_TEMPORARY_DIRECTORY_HH_

#include <boost/filesystem/path.hpp>

namespace fix {
struct temporary_directory {
    explicit temporary_directory(boost::filesystem::path p);
    temporary_directory();
    ~temporary_directory();
    temporary_directory(temporary_directory const&) = delete;
    temporary_directory& operator=(temporary_directory const&) = delete;
    temporary_directory(temporary_directory&& rhs);
    temporary_directory& operator=(temporary_directory&& rhs);

    boost::filesystem::path path() const;

private:
    boost::filesystem::path temp_path;
};

void swap(temporary_directory& lhs, temporary_directory& rhs);
}  // namespace fix

#include "temporary_directory.tcc"

#endif  // FIX_TEMPORARY_DIRECTORY_HH_
