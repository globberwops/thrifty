
#pragma once

#include "entt/entity/fwd.hpp"
#include "spdlog/spdlog.h"

#include <memory>

#include "interfaces/IRunnable.h"
#include "units/Units.h"

namespace thrifty::entities
{
using registry_t = entt::registry;
using entity_t = entt::entity;

class EntityController final : public interfaces::IRunnable<units::time_t, registry_t, entity_t>
{
    std::shared_ptr<registry_t> mRegistry;

  public:
    void Update(units::time_t dt, std::shared_ptr<registry_t> registry, entity_t entity) noexcept override;

    auto Registry() -> std::shared_ptr<registry_t>;

    [[nodiscard]] auto CreateEntity() -> entity_t;

    static auto GetLogger() -> std::shared_ptr<spdlog::logger>;

    EntityController();
    EntityController(EntityController &&other) = default;
    EntityController(const EntityController &other) = default;
    auto operator=(EntityController &&other) -> EntityController & = default;
    auto operator=(const EntityController &other) -> EntityController & = default;
    ~EntityController() override = default;
};

} // namespace thrifty::entities
