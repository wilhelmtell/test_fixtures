#ifndef FIXTURES_TEMPORARY_DIRECTORY_HH_
#define FIXTURES_TEMPORARY_DIRECTORY_HH_

#include <boost/filesystem/path.hpp>

namespace fixtures {
struct temporary_directory {
    explicit temporary_directory(boost::filesystem::path p);
    temporary_directory();
    ~temporary_directory();
    temporary_directory(temporary_directory const&) = delete;
    temporary_directory& operator=(temporary_directory const&) = delete;

    boost::filesystem::path path() const;

private:
    boost::filesystem::path temp_path;
};
}  // namespace fixtures

#include "temporary_directory.tcc"

#endif  // FIXTURES_TEMPORARY_DIRECTORY_HH_
