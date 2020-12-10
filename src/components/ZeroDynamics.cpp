

#include "entt/entt.hpp"   // for entt::registry
#include "spdlog/spdlog.h" // for spdlog::logger

#include <memory> // for std::weak_ptr

#include "units/Units.h"

#include "components/ZeroDynamics.h"

namespace thrifty::entities
{

void ZeroDynamics::Update(units::time_t dt, std::shared_ptr<registry_t> registry, entity_t entity) noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    auto [pos, vel, acc] =
        registry->get<units::position_sixdof_t, units::velocity_sixdof_t, units::acceleration_sixdof_t>(entity);

    vel += acc * dt;
    pos += vel * dt;
}

} // namespace thrifty::entities
