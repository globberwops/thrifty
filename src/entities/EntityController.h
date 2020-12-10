//===-- entities/EntityController.h - EntityController class ----*- C++ -*-===//
//
// Part of the Thrifty Project, under the Boost Software License 1.0.
// See the https://opensource.org/licenses/BSL-1.0 for license information.
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the EntityController class.
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef THRIFTY_ENTITIES_ENTITY_CONTROLLER_H
#define THRIFTY_ENTITIES_ENTITY_CONTROLLER_H

#include "entt/entity/fwd.hpp" // for entt::registry
#include "spdlog/spdlog.h"     // for spdlog::logger

#include <memory> // for std::shared_ptr

#include "entities/IRunnable.h" // for thrifty::entities::IRunnable

namespace thrifty::entities
{

class EntityController final : public IRunnable
{
    std::shared_ptr<entt::registry> mRegistry;

  public:
    void Update(units::time::second_t dt) noexcept override;

    auto Registry() -> std::shared_ptr<entt::registry>;

    [[nodiscard]] auto CreateEntity() -> entt::entity;

    static auto GetLogger() -> std::shared_ptr<spdlog::logger>;

    EntityController();
    EntityController(EntityController &&other) = default;
    EntityController(const EntityController &other) = default;
    auto operator=(EntityController &&other) -> EntityController & = default;
    auto operator=(const EntityController &other) -> EntityController & = default;
    ~EntityController() override = default;
};

} // namespace thrifty::entities

#endif // THRIFTY_ENTITIES_ENTITY_CONTROLLER_H
