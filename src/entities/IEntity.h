#pragma once

#include <memory>
#include <string>  // for std::string
#include <utility> // for std::move

#include "Position.h"

namespace thrifty::entities
{

class IEntity
{
    std::string mId{};
    Position mPosition{};

  public:
    [[nodiscard]] auto GetId() const noexcept -> std::string
    {
        return mId;
    }

    void SetId(std::string id) noexcept
    {
        mId = std::move(id);
    }

    [[nodiscard]] auto GetPosition() const noexcept -> Position
    {
        return mPosition;
    }

    void SetPosition(const Position &position) noexcept
    {
        mPosition = position;
    }

    auto operator<(const IEntity &other) const -> bool
    {
        return mId < other.mId;
    }

    auto operator>(const IEntity &other) const -> bool
    {
        return mId > other.mId;
    }

    explicit IEntity(std::string id = {}, Position position = {}) : mId(std::move(id)), mPosition(position){};
    IEntity(const IEntity &other) = default;
    IEntity(IEntity &&other) = default;
    auto operator=(const IEntity &other) -> IEntity & = default;
    auto operator=(IEntity &&other) -> IEntity & = default;
    virtual ~IEntity() = default;
};

} // namespace thrifty::entities
