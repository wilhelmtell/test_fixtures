#ifndef FIX_TEMPORARY_FILE_HH_
#define FIX_TEMPORARY_FILE_HH_

#include <boost/filesystem/path.hpp>

namespace fix {
struct temporary_file {
    explicit temporary_file(boost::filesystem::path p);
    temporary_file();
    temporary_file(temporary_file&& rhs);
    ~temporary_file();
    temporary_file(temporary_file const&) = delete;
    temporary_file& operator=(temporary_file const&) = delete;
    temporary_file& operator=(temporary_file&& rhs);

    boost::filesystem::path path() const;

private:
    boost::filesystem::path file_path;
};

void swap(temporary_file& lhs, temporary_file& rhs);
template<typename T>
temporary_file& operator<<(temporary_file& out, T const& value);
template<typename T>
temporary_file& operator>>(temporary_file& in, T& value);
}  // namespace fix

#include "temporary_file.tcc"

#endif  // FIX_TEMPORARY_FILE_HH_
