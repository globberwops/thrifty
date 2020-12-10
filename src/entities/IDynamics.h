//===-- entities/IDynamics.h - IDynamics struct definition ------*- C++ -*-===//
//
// Part of the Thrifty Project, under the Boost Software License 1.0.
// See the https://opensource.org/licenses/BSL-1.0 for license information.
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the IDynamics struct, which is the
/// interface for all driving dynamics implementations.
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef THRIFTY_ENTITIES_I_DYNAMICS_H
#define THRIFTY_ENTITIES_I_DYNAMICS_H

#include "entt/entity/fwd.hpp" // entt::registry
#include "units.h"             // for units::time::second_t

#include <memory> // for std::weak_ptr

namespace thrifty::entities
{

struct IDynamics
{
    virtual void Update(units::time::second_t dt, std::weak_ptr<entt::registry> registry,
                        entt::entity entity) noexcept = 0;

    IDynamics() = default;
    IDynamics(const IDynamics &other) = default;
    IDynamics(IDynamics &&other) = default;
    auto operator=(const IDynamics &other) -> IDynamics & = default;
    auto operator=(IDynamics &&other) -> IDynamics & = default;
    virtual ~IDynamics() = default;
};

} // namespace thrifty::entities

#endif // THRIFTY_ENTITIES_I_DYNAMICS_H
