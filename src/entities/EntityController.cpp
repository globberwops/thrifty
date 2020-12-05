#include <algorithm> // for std::find_if
#include <memory>    // for std::shared_ptr
#include <vector>    // for std::vector

#include "spdlog/spdlog.h"

#include "entities/IEntity.h"
#include "entities/IRunnable.h"

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

void EntityController::AddEntity(const std::shared_ptr<IEntity> &entity) noexcept
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    if (mEntities.contains(entity))
    {
        spdlog::error("An entity with id '{}' already exists. Ids have to be unique!", entity->GetId());

        return;
    }

    mEntities.insert(entity);
}

auto EntityController::GetLogger() -> std::shared_ptr<spdlog::logger>
{
    SPDLOG_TRACE(__PRETTY_FUNCTION__);

    return spdlog::default_logger();
}

} // namespace thrifty::entities
