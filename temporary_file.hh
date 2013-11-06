#ifndef FIXTURES_TEMPORARY_FILE_HH_
#define FIXTURES_TEMPORARY_FILE_HH_

#include <boost/filesystem/path.hpp>

namespace fixtures {
struct temporary_file {
    explicit temporary_file(boost::filesystem::path p);
    temporary_file();
    ~temporary_file();
    temporary_file(temporary_file const&) = delete;
    temporary_file& operator=(temporary_file const&) = delete;

    boost::filesystem::path path() const;

private:
    boost::filesystem::path file_path;
};
}  // namespace fixtures

#include "temporary_file.tcc"

#endif  // FIXTURES_TEMPORARY_FILE_HH_
