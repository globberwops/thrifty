#pragma once

#include "entt/entity/fwd.hpp" // for entt::registry
#include "units.h"             // for units::time::second_t

#include "entities/IDynamics.h" // for thrifty::entities::IDynamics

namespace thrifty::entities
{

struct ZeroDynamics : IDynamics
{
    void Update(units::time::second_t dt, entt::registry &registry, entt::entity entity) noexcept override;

    ZeroDynamics() = default;
    ZeroDynamics(const ZeroDynamics &other) = default;
    ZeroDynamics(ZeroDynamics &&other) = default;
    auto operator=(const ZeroDynamics &other) -> ZeroDynamics & = default;
    auto operator=(ZeroDynamics &&other) -> ZeroDynamics & = default;
    ~ZeroDynamics() override = default;
};

} // namespace thrifty::entities
