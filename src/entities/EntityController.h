#pragma once

#include <algorithm>     // for std::find_if
#include <memory>        // for std::shared_ptr
#include <unordered_set> // for std::unordered_set
#include <vector>        // for std::vector

#include "spdlog/spdlog.h"

#include "entities/IEntity.h"   // for thrifty::entities::IEntity
#include "entities/IRunnable.h" // for thrifty::entities::IRunnable

namespace thrifty::entities
{

class EntityController final : public IRunnable
{
    using entity_container_t = std::unordered_set<std::shared_ptr<IEntity>>;

    entity_container_t mEntities;

  public:
    void Init() noexcept override;
    void Start() noexcept override;
    void Pause() noexcept override;
    void Stop() noexcept override;

    template <typename T = IEntity> //
    [[nodiscard]] auto GetEntities() noexcept -> entity_container_t
    {
        SPDLOG_TRACE(__PRETTY_FUNCTION__);

        entity_container_t entities;

        for (auto &&e : mEntities)
        {
            if (auto type = std::dynamic_pointer_cast<T>(e); type)
            {
                entities.insert(type);
            }
        }

        return entities;
    }

    template <typename T = IEntity> //
    [[nodiscard]] auto GetEntity(const std::string &id) -> std::shared_ptr<T>
    {
        SPDLOG_TRACE(__PRETTY_FUNCTION__);

        if (auto it{
                std::find_if(std::begin(mEntities), std::end(mEntities), [id](auto &&e) { return e->GetId() == id; })};
            it != std::end(mEntities))
        {
            return std::dynamic_pointer_cast<T>(*it);
        }

        spdlog::error("An entity with id '{}' does not exist!", id);

        return nullptr;
    }

    void AddEntity(const std::shared_ptr<IEntity> &entity) noexcept;

    template <typename T = IEntity> //
    [[nodiscard]] auto CreateEntity(const std::string &id = {}) -> std::shared_ptr<IEntity>
    {
        SPDLOG_TRACE(__PRETTY_FUNCTION__);

        static_assert(std::is_convertible_v<T *, IEntity *>);

        auto entity{std::make_shared<IEntity>(id)};
        mEntities.insert(entity);

        return entity;
    }

    static auto GetLogger() -> std::shared_ptr<spdlog::logger>;

    EntityController() = default;
    ~EntityController() override = default;
    EntityController(EntityController &&other) noexcept = default;
    EntityController(const EntityController &other) = default;
    auto operator=(EntityController &&other) noexcept -> EntityController & = default;
    auto operator=(const EntityController &other) -> EntityController & = default;
};

} // namespace thrifty::entities
