#pragma once

namespace thrifty::entities
{

struct IRunnable
{
    virtual void Init() noexcept = 0;
    virtual void Start() noexcept = 0;
    virtual void Pause() noexcept = 0;
    virtual void Stop() noexcept = 0;

    IRunnable() = default;
    IRunnable(const IRunnable &other) = default;
    IRunnable(IRunnable &&other) = default;
    auto operator=(const IRunnable &other) -> IRunnable & = default;
    auto operator=(IRunnable &&other) -> IRunnable & = default;
    virtual ~IRunnable() = default;
};

} // namespace thrifty::entities
