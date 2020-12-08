#pragma once

#include "units.h" // for units::time::second_t

namespace thrifty::entities
{

class IRunnable
{
  public:
    enum class RunState : std::size_t
    {
        kInitialized = 0,
        kStarted,
        kPaused,
        kStopped
    };

    virtual void Init() noexcept = 0;
    virtual void Start() noexcept = 0;
    virtual void Pause() noexcept = 0;
    virtual void Stop() noexcept = 0;
    virtual void Update(units::time::second_t dt) noexcept = 0;

    auto GetRunState() noexcept
    {
        return mRunState;
    }

    IRunnable() = default;
    IRunnable(const IRunnable &other) = default;
    IRunnable(IRunnable &&other) = default;
    auto operator=(const IRunnable &other) -> IRunnable & = default;
    auto operator=(IRunnable &&other) -> IRunnable & = default;
    virtual ~IRunnable() = default;

  protected:
    void SetRunState(RunState state)
    {
        mRunState = state;
    }

  private:
    RunState mRunState{};
};

} // namespace thrifty::entities
