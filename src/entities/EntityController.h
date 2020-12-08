#pragma once

#include <memory> // for std::shared_ptr

#include "entt/entity/fwd.hpp"
#include "entt/entt.hpp"   // for entt::registry
#include "spdlog/spdlog.h" // for spdlog::logger

#include "entities/IRunnable.h" // for thrifty::entities::IRunnable

namespace thrifty::entities
{

class EntityController final : public IRunnable
{
    std::shared_ptr<entt::registry> mRegistry;

  public:
    void Init() noexcept override;
    void Start() noexcept override;
    void Pause() noexcept override;
    void Stop() noexcept override;

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
