#include "entt/entt.hpp"   // for entt::registry
#include "spdlog/spdlog.h" // for spdlog::logger

#include "entities/Acceleration.h" // for thrifty::entities::Acceleration
#include "entities/Position.h"     // for thrifty::entities::Position
#include "entities/Velocity.h"     // for thrifty::entities::Velocity
#include "entities/ZeroDynamics.h" // for thrifty::entities::ZeroDynamics

#include "entities/IRunnable.h" // for thrifty::entities::IRunnable

#include "entities/EntityController.h"

namespace thrifty::entities
{

using RunState = IRunnable::RunState;

void EntityController::Init() noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    SetRunState(RunState::kInitialized);
}

void EntityController::Start() noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    SetRunState(RunState::kStarted);
}

void EntityController::Pause() noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    SetRunState(RunState::kPaused);
}

void EntityController::Stop() noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    SetRunState(RunState::kStopped);
}

void EntityController::Update(units::time::second_t dt) noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    if (GetRunState() != RunState::kStarted)
    {
        return;
    }

    mRegistry.view<ZeroDynamics>().each([this, dt](auto entity, auto &dyn) { dyn.Update(dt, mRegistry, entity); });
}

auto EntityController::GetRegistry() -> entt::registry &
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    return mRegistry;
}

auto EntityController::operator()() -> entt::registry &
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
    mRegistry.emplace<Acceleration>(entity);
    mRegistry.emplace<ZeroDynamics>(entity);

    return entity;
}

auto EntityController::GetLogger() -> std::shared_ptr<spdlog::logger>
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    return spdlog::default_logger();
}

} // namespace thrifty::entities
