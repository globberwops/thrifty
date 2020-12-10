

#pragma once

#include <memory>

namespace thrifty::interfaces
{
template <typename Time, typename Registry, typename Entity> //
struct IRunnable
{
    virtual void Update(Time dt, std::shared_ptr<Registry> registry, Entity entity) noexcept = 0;

    IRunnable() = default;
    IRunnable(const IRunnable &other) = default;
    IRunnable(IRunnable &&other) noexcept = default;
    auto operator=(const IRunnable &other) -> IRunnable & = default;
    auto operator=(IRunnable &&other) noexcept -> IRunnable & = default;
    virtual ~IRunnable() = default;
};

} // namespace thrifty::interfaces
