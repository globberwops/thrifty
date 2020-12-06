#include <algorithm> // for std::find_if
#include <memory>    // for std::shared_ptr
#include <vector>    // for std::vector

#include "entt/entt.hpp"
#include "spdlog/spdlog.h"

#include "entities/IRunnable.h"
#include "entities/Position.h"
#include "entities/Velocity.h"

#include "entities/EntityController.h"

namespace thrifty::entities
{

void EntityController::Init() noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);
}

void EntityController::Start() noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);
}

void EntityController::Pause() noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);
}

void EntityController::Stop() noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);
}

void EntityController::Update(units::time::second_t dt) noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    mRegistry.view<Position, Velocity>().each([dt](auto &pos, auto &vel) {
        pos.x += vel.dx * dt;
        pos.y += vel.dy * dt;
        pos.z += vel.dz * dt;
        pos.h += vel.dh * dt;
        pos.p += vel.dp * dt;
        pos.r += vel.dr * dt;
    });
}

auto EntityController::GetRegistry() -> entt::registry &
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    return mRegistry;
}

auto EntityController::CreateEntity() -> entt::entity
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    auto entity = mRegistry.create();
    mRegistry.emplace<Position>(entity);
    mRegistry.emplace<Velocity>(entity);

    return entity;
}

auto EntityController::GetLogger() -> std::shared_ptr<spdlog::logger>
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    return spdlog::default_logger();
}

} // namespace thrifty::entities
