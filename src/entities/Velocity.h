#pragma once

#include "units.h"

#include "entities/Position.h" // for thrifty::entities::Position

namespace thrifty::entities
{
struct Velocity
{
    units::velocity::meters_per_second_t x, y, z;          // NOLINT(readability-identifier-naming)
    units::angular_velocity::radians_per_second_t h, p, r; // NOLINT(readability-identifier-naming)
};

constexpr auto operator+(const Velocity lhs, const Velocity rhs) -> Velocity
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.h + rhs.h, lhs.p + rhs.p, lhs.r + rhs.r};
}

constexpr auto operator+=(Velocity &lhs, const Velocity rhs) -> Velocity &
{
    return lhs = lhs + rhs;
}

constexpr auto operator-(const Velocity lhs, const Velocity rhs) -> Velocity
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.h - rhs.h, lhs.p - rhs.p, lhs.r - rhs.r};
}

constexpr auto operator*(const Velocity lhs, const units::time::second_t rhs) -> Position
{
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.h * rhs, lhs.p * rhs, lhs.r * rhs};
}

constexpr auto operator==(const Velocity lhs, const Velocity rhs) -> bool
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.h == rhs.h && lhs.p == rhs.p && lhs.r == rhs.r;
}

constexpr auto operator!=(const Velocity lhs, const Velocity rhs) -> bool
{
    return !(lhs == rhs);
}
} // namespace thrifty::entities
