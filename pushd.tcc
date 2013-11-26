#ifndef FIX_PUSHD_TCC_
#define FIX_PUSHD_TCC_

#include "pushd.hh"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>

namespace fix {
inline pushd::pushd(boost::filesystem::path const& p)
: original_path(boost::filesystem::current_path())
{
    boost::filesystem::current_path(p);
}

inline pushd::~pushd()
{
    boost::system::error_code err;
    boost::filesystem::current_path(original_path, err);
}
}  // namespace fix

#endif  // FIX_PUSHD_TCC_
