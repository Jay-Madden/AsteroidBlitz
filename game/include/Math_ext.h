#include <cmath>

#ifndef M_PI
#define M_PI (4.0 * std::atan2(1.0, 1.0))
#endif

#ifndef MATHEXT_H
#define MATHEXT_H

template <typename N> inline
N deg2rad( N d )
{
    return M_PI * d / 180.0;
}

template <typename N> inline
N rad2deg( N r )
{
    return 180.0 * r / M_PI;
}

#endif