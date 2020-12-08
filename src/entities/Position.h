#pragma once

#include "units.h"

namespace thrifty::entities
{
struct Position
{
    units::length::meter_t x, y, z; // NOLINT(readability-identifier-naming)
    units::angle::radian_t h, p, r; // NOLINT(readability-identifier-naming)
};

constexpr auto operator+(const Position lhs, const Position rhs) -> Position
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.h + rhs.h, lhs.p + rhs.p, lhs.r + rhs.r};
}

constexpr auto operator+=(Position &lhs, const Position rhs) -> Position &
{
    return lhs = lhs + rhs;
}

constexpr auto operator-(const Position lhs, const Position rhs) -> Position
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.h - rhs.h, lhs.p - rhs.p, lhs.r - rhs.r};
}

constexpr auto operator*(const Position lhs, const double rhs) -> Position
{
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.h * rhs, lhs.p * rhs, lhs.r * rhs};
}

constexpr auto operator==(const Position lhs, const Position rhs) -> bool
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.h == rhs.h && lhs.p == rhs.p && lhs.r == rhs.r;
}

constexpr auto operator!=(const Position lhs, const Position rhs) -> bool
{
    return !(lhs == rhs);
}

inline auto distance(const Position a, const Position b) -> units::length::meter_t
{
    const auto dx = a.x - b.x;
    const auto dy = a.y - b.y;
    const auto dz = a.z - b.z;
    return units::math::sqrt(dx * dx + dy * dy + dz * dz);
}

inline auto operator<<(std::ostream &os, const Position &pos) -> std::ostream &
{
    os << "Position ( x=" << pos.x << ", y=" << pos.y << ", z=" << pos.z << ", h=" << pos.h << ", p=" << pos.p
       << ", r=" << pos.r << " )";
    return os;
}
} // namespace thrifty::entities
