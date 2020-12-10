//===-- entities/EntityController.cpp - EntityController class ------------===//
//
// Part of the Thrifty Project, under the Boost Software License 1.0.
// See the https://opensource.org/licenses/BSL-1.0 for license information.
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the definition of the EntityController class.
///
//===----------------------------------------------------------------------===//

#include "entt/entt.hpp"   // for entt::registry
#include "spdlog/spdlog.h" // for spdlog::logger
#include "units.h"

#include <memory> // for std::shared_ptr

#include "entities/SixDoF.h"       // for thrifty::entities::SixDoF
#include "entities/ZeroDynamics.h" // for thrifty::entities::ZeroDynamics

#include "entities/IRunnable.h" // for thrifty::entities::IRunnable

#include "entities/EntityController.h"

namespace thrifty::entities
{

void EntityController::Update(units::time::second_t dt) noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    mRegistry->view<ZeroDynamics>().each([this, dt](auto entity, auto &dyn) { dyn.Update(dt, mRegistry, entity); });
}

auto EntityController::Registry() -> std::shared_ptr<entt::registry>
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    return mRegistry;
}

auto EntityController::CreateEntity() -> entt::entity
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    auto entity = mRegistry->create();
    mRegistry->emplace<Position_t>(entity);
    mRegistry->emplace<Velocity_t>(entity);
    mRegistry->emplace<Acceleration_t>(entity);
    mRegistry->emplace<ZeroDynamics>(entity);

    return entity;
}

auto EntityController::GetLogger() -> std::shared_ptr<spdlog::logger>
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    return spdlog::default_logger();
}

EntityController::EntityController() : mRegistry(std::make_shared<entt::registry>())
{
}

} // namespace thrifty::entities
