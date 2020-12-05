#pragma once

#include <units.h>

namespace thrifty::entities
{
struct Position
{
    units::angle::radian_t mX, mY, mZ;
    units::length::meter_t mH, mP, mR;
};
} // namespace thrifty::entities
