//===-- entities/ZeroDynamics.h - ZeroDynamics definition -------*- C++ -*-===//
//
// Part of the Thrifty Project, under the Boost Software License 1.0.
// See the https://opensource.org/licenses/BSL-1.0 for license information.
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ZeroDynamics struct.
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef THRIFTY_ENTITIES_ZERO_DYNAMICS_H
#define THRIFTY_ENTITIES_ZERO_DYNAMICS_H

#include "entt/entity/fwd.hpp" // for entt::registry
#include "units.h"             // for units::time::second_t

#include <memory> // for std::weak_ptr

#include "entities/IDynamics.h" // for thrifty::entities::IDynamics

namespace thrifty::entities
{

struct ZeroDynamics : IDynamics
{
    void Update(units::time::second_t dt, std::weak_ptr<entt::registry> registry,
                entt::entity entity) noexcept override;

    ZeroDynamics() = default;
    ZeroDynamics(const ZeroDynamics &other) = default;
    ZeroDynamics(ZeroDynamics &&other) = default;
    auto operator=(const ZeroDynamics &other) -> ZeroDynamics & = default;
    auto operator=(ZeroDynamics &&other) -> ZeroDynamics & = default;
    ~ZeroDynamics() override = default;
};

} // namespace thrifty::entities

#endif // THRIFTY_ENTITIES_ZERO_DYNAMICS_H
