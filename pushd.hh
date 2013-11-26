#ifndef FIX_PUSHD_HH_
#define FIX_PUSHD_HH_

#include <boost/filesystem/path.hpp>

namespace fix {
struct pushd {
    explicit pushd(boost::filesystem::path const& p);
    pushd() = default;
    ~pushd();
    pushd(pushd const&) = delete;
    pushd& operator=(pushd const&) = delete;
    pushd(pushd&& rhs) = default;
    pushd& operator=(pushd&&) = default;

private:
    boost::filesystem::path original_path;
};
}  // namespace fix

#include "pushd.tcc"

#endif  // FIX_PUSHD_HH_
