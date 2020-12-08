#pragma once

#include "entt/entt.hpp"   // for entt::registry
#include "spdlog/spdlog.h" // for spdlog::logger

#include "entities/IRunnable.h" // for thrifty::entities::IRunnable

namespace thrifty::entities
{

class EntityController final : public IRunnable
{
    entt::registry mRegistry;

  public:
    void Init() noexcept override;
    void Start() noexcept override;
    void Pause() noexcept override;
    void Stop() noexcept override;

    void Update(units::time::second_t dt) noexcept override;

    auto GetRegistry() -> entt::registry &;
    auto operator()() -> entt::registry &;

    [[nodiscard]] auto CreateEntity() -> entt::entity;

    static auto GetLogger() -> std::shared_ptr<spdlog::logger>;

    EntityController() = default;
    ~EntityController() override = default;
    EntityController(EntityController &&other) noexcept = default;
    EntityController(const EntityController &other) = delete;
    auto operator=(EntityController &&other) noexcept -> EntityController & = default;
    auto operator=(const EntityController &other) -> EntityController & = delete;
};

} // namespace thrifty::entities
