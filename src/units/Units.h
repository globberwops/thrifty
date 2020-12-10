#pragma once

#include "units.h"
#include <type_traits>

namespace units
{
// NOLINTNEXTLINE(modernize-use-trailing-return-type)
UNIT_ADD(angular_acceleration, radians_per_second_squared, radians_per_second_squared, rad_per_s_sq,
         compound_unit<units::angle::radians, inverse<squared<units::time::seconds>>>)
} // namespace units

namespace thrifty::units
{

template <typename Length, typename Angle> //
struct SixDoF
{
    Length x, y, z; // NOLINT(readability-identifier-naming)
    Angle h, p, r;  // NOLINT(readability-identifier-naming)
};

template <typename Length, typename Angle> //
constexpr auto operator+(const SixDoF<Length, Angle> lhs, const SixDoF<Length, Angle> rhs) -> SixDoF<Length, Angle>
{
    return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.h + rhs.h, lhs.p + rhs.p, lhs.r + rhs.r};
}

template <typename Length, typename Angle> //
constexpr auto operator+=(SixDoF<Length, Angle> &lhs, const SixDoF<Length, Angle> rhs) -> SixDoF<Length, Angle> &
{
    return lhs = lhs + rhs;
}

template <typename Length, typename Angle> //
constexpr auto operator-(const SixDoF<Length, Angle> lhs, const SixDoF<Length, Angle> rhs) -> SixDoF<Length, Angle>
{
    return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.h - rhs.h, lhs.p - rhs.p, lhs.r - rhs.r};
}

template <typename Length, typename Angle> //
constexpr auto operator-=(SixDoF<Length, Angle> &lhs, const SixDoF<Length, Angle> rhs) -> SixDoF<Length, Angle> &
{
    return lhs = lhs - rhs;
}

template <typename Length, typename Angle, typename Multiplicand> //
constexpr auto operator*(const SixDoF<Length, Angle> lhs, const Multiplicand rhs)
    -> SixDoF<decltype(lhs.x * rhs), decltype(lhs.h * rhs)>
{
    return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.h * rhs, lhs.p * rhs, lhs.r * rhs};
}

template <typename Length, typename Angle, typename Multiplicand> //
constexpr auto operator*=(SixDoF<Length, Angle> &lhs, const Multiplicand rhs) -> SixDoF<Length, Angle> &
{
    static_assert(std::is_arithmetic_v<Multiplicand>, "Multiplicand is not an arithmetic type");

    return lhs = lhs * rhs;
}

template <typename Length, typename Angle, typename Divisor> //
constexpr auto operator/(const SixDoF<Length, Angle> lhs, const Divisor rhs)
    -> SixDoF<decltype(lhs.x / rhs), decltype(lhs.h / rhs)>
{
    return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.h / rhs, lhs.p / rhs, lhs.r / rhs};
}

template <typename Length, typename Angle, typename Divisor> //
constexpr auto operator/=(SixDoF<Length, Angle> &lhs, const Divisor rhs)
    -> SixDoF<decltype(lhs.x / rhs), decltype(lhs.h / rhs)>
{
    static_assert(std::is_arithmetic_v<Divisor>, "Divisor is not an arithmetic type");

    return lhs = lhs / rhs;
}

template <typename Length, typename Angle> //
constexpr auto operator==(const SixDoF<Length, Angle> lhs, const SixDoF<Length, Angle> rhs) -> bool
{
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.h == rhs.h && lhs.p == rhs.p && lhs.r == rhs.r;
}

template <typename Length, typename Angle> //
constexpr auto operator!=(const SixDoF<Length, Angle> lhs, const SixDoF<Length, Angle> rhs) -> bool
{
    return !(lhs == rhs);
}

template <typename Length, typename Angle> //
inline auto distance(const SixDoF<Length, Angle> a, const SixDoF<Length, Angle> b) -> Length
{
    const auto dx = a.x - b.x;
    const auto dy = a.y - b.y;
    const auto dz = a.z - b.z;
    return ::units::math::sqrt(dx * dx + dy * dy + dz * dz); // TODO(globberwops): Do not depend on units lib
}

template <typename Length, typename Angle> //
inline auto operator<<(std::ostream &os, const SixDoF<Length, Angle> &a) -> std::ostream &
{
    os << "SixDoF ( x=" << a.x << ", y=" << a.y << ", z=" << a.z << ", h=" << a.h << ", p=" << a.p << ", r=" << a.r
       << " )";
    return os;
}

using time_t = ::units::time::second_t;
using position_sixdof_t = SixDoF<::units::length::meter_t, ::units::angle::radian_t>;
using velocity_sixdof_t =
    SixDoF<::units::velocity::meters_per_second_t, ::units::angular_velocity::radians_per_second_t>;
using acceleration_sixdof_t = SixDoF<::units::acceleration::meters_per_second_squared_t,
                                     ::units::angular_acceleration::radians_per_second_squared_t>;

} // namespace thrifty::units
