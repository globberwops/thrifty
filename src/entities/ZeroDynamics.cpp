//===-- entities/ZeroDynamics.cpp - ZeroDynamics definition ---------------===//
//
// Part of the Thrifty Project, under the Boost Software License 1.0.
// See the https://opensource.org/licenses/BSL-1.0 for license information.
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the definition of the ZeroDynamics struct.
///
//===----------------------------------------------------------------------===//

#include "entt/entt.hpp"   // for entt::registry
#include "spdlog/spdlog.h" // for spdlog::logger

#include <memory> // for std::weak_ptr

#include "entities/SixDoF.h"

#include "entities/ZeroDynamics.h"

namespace thrifty::entities
{

void ZeroDynamics::Update(units::time::second_t dt, std::weak_ptr<entt::registry> registry,
                          entt::entity entity) noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    if (auto reg = registry.lock())
    {
        auto [pos, vel, acc] = reg->get<Position_t, Velocity_t, Acceleration_t>(entity);

        vel += acc * dt;
        pos += vel * dt;
    }
}

} // namespace thrifty::entities
