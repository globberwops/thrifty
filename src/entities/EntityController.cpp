#include "entt/entt.hpp"
#include "spdlog/spdlog.h"
#include "units.h"

#include <memory>

#include "components/ZeroDynamics.h"
#include "interfaces/IRunnable.h"
#include "units/Units.h"

#include "entities/EntityController.h"

namespace thrifty::entities
{

void EntityController::Update(units::time_t dt, std::shared_ptr<registry_t> /*registry*/, entity_t /*entity*/) noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    mRegistry->view<ZeroDynamics>().each([this, dt](auto entity, auto &dyn) { dyn.Update(dt, mRegistry, entity); });
}

auto EntityController::Registry() -> std::shared_ptr<registry_t>
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    return mRegistry;
}

auto EntityController::CreateEntity() -> entity_t
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    auto entity = mRegistry->create();
    mRegistry->emplace<units::position_sixdof_t>(entity);
    mRegistry->emplace<units::velocity_sixdof_t>(entity);
    mRegistry->emplace<units::acceleration_sixdof_t>(entity);
    mRegistry->emplace<ZeroDynamics>(entity);

    return entity;
}

auto EntityController::GetLogger() -> std::shared_ptr<spdlog::logger>
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    return spdlog::default_logger();
}

EntityController::EntityController() : mRegistry(std::make_shared<registry_t>())
{
}

} // namespace thrifty::entities
