#pragma once

#include <units.h>

namespace thrifty::entities
{
struct Velocity
{
    units::velocity::meters_per_second_t dx, dy, dz;          // NOLINT(readability-identifier-naming)
    units::angular_velocity::radians_per_second_t dh, dp, dr; // NOLINT(readability-identifier-naming)
};
} // namespace thrifty::entities
