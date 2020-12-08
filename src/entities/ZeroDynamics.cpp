#include "entt/entt.hpp"   // for entt::registry
#include "spdlog/spdlog.h" // for spdlog::logger
#include "units.h"         // for units::time::second_t

#include "entities/Acceleration.h" // for thrifty::entities::Acceleration
#include "entities/Position.h"     // for thrifty::entities::Position
#include "entities/Velocity.h"     // for thrifty::entities::Velocity

#include "entities/ZeroDynamics.h"

namespace thrifty::entities
{

void ZeroDynamics::Update(units::time::second_t dt, entt::registry &registry, entt::entity entity) noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    auto [pos, vel, acc] = registry.get<Position, Velocity, Acceleration>(entity);

    vel += acc * dt;
    pos += vel * dt;
}

} // namespace thrifty::entities
