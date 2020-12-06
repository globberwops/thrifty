#pragma once

#include <units.h>

namespace thrifty::entities
{
struct Position
{
    units::length::meter_t x, y, z; // NOLINT(readability-identifier-naming)
    units::angle::radian_t h, p, r; // NOLINT(readability-identifier-naming)
};
} // namespace thrifty::entities
