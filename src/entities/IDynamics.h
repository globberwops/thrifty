#pragma once

#include "entt/entity/fwd.hpp" // entt::registry
#include "units.h"             // for units::time::second_t

namespace thrifty::entities
{

class IDynamics
{
  public:
    virtual void Update(units::time::second_t dt, entt::registry &registry, entt::entity entity) noexcept = 0;

    IDynamics() = default;
    IDynamics(const IDynamics &other) = default;
    IDynamics(IDynamics &&other) = default;
    auto operator=(const IDynamics &other) -> IDynamics & = default;
    auto operator=(IDynamics &&other) -> IDynamics & = default;
    virtual ~IDynamics() = default;
};

} // namespace thrifty::entities
