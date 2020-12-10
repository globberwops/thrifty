

#pragma once

#include "entt/entity/fwd.hpp"

#include <memory>

#include "interfaces/IRunnable.h"
#include "units/Units.h"

namespace thrifty::entities
{
using registry_t = entt::registry;
using entity_t = entt::entity;

struct ZeroDynamics final : public interfaces::IRunnable<units::time_t, registry_t, entity_t>
{
    void Update(units::time_t dt, std::shared_ptr<registry_t> registry, entity_t entity) noexcept override;

    ZeroDynamics() = default;
    ZeroDynamics(const ZeroDynamics &other) = default;
    ZeroDynamics(ZeroDynamics &&other) = default;
    auto operator=(const ZeroDynamics &other) -> ZeroDynamics & = default;
    auto operator=(ZeroDynamics &&other) -> ZeroDynamics & = default;
    ~ZeroDynamics() override = default;
};

} // namespace thrifty::entities
