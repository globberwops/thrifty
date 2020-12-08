#pragma once

#include "units.h"

#include "entities/Velocity.h" // for thrifty::entities::Velocity

namespace units
{
// NOLINTNEXTLINE(modernize-use-trailing-return-type)
UNIT_ADD(angular_acceleration, radians_per_second_squared, radians_per_second_squared, rad_per_s_sq,
         compound_unit<units::angle::radians, inverse<squared<units::time::seconds>>>)
} // namespace units

namespace thrifty::entities
{
struct Acceleration
{
    units::acceleration::meters_per_second_squared_t x, y, z;          // NOLINT(readability-identifier-naming)
    units::angular_acceleration::radians_per_second_squared_t h, p, r; // NOLINT(readability-identifier-naming)
};

constexpr auto operator+(const Acceleration lhs, const Acceleration rhs) -> Acceleration
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.h + rhs.h, lhs.p + rhs.p, lhs.r + rhs.r};
}

constexpr auto operator+=(Acceleration &lhs, const Acceleration rhs) -> Acceleration &
{
    return lhs = lhs + rhs;
}

constexpr auto operator-(const Acceleration lhs, const Acceleration rhs) -> Acceleration
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.h - rhs.h, lhs.p - rhs.p, lhs.r - rhs.r};
}

constexpr auto operator*(const Acceleration lhs, const units::time::second_t rhs) -> Velocity
{
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.h * rhs, lhs.p * rhs, lhs.r * rhs};
}

constexpr auto operator==(const Acceleration lhs, const Acceleration rhs) -> bool
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.h == rhs.h && lhs.p == rhs.p && lhs.r == rhs.r;
}

constexpr auto operator!=(const Acceleration lhs, const Acceleration rhs) -> bool
{
    return !(lhs == rhs);
}

inline auto operator<<(std::ostream &os, const Acceleration &acc) -> std::ostream &
{
    os << "Acceleration ( x=" << acc.x << ", y=" << acc.y << ", z=" << acc.z << ", h=" << acc.h << ", p=" << acc.p
       << ", r=" << acc.r << " )";
    return os;
}
} // namespace thrifty::entities
