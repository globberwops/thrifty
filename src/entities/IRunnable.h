//===-- entities/IRunnable.h - IRunnable class definition -------*- C++ -*-===//
//
// Part of the Thrifty Project, under the Boost Software License 1.0.
// See the https://opensource.org/licenses/BSL-1.0 for license information.
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the IRunnable class, which is the
/// interface for all classes to be considered "runnable".
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef THRIFTY_ENTITIES_I_RUNNABLE_H
#define THRIFTY_ENTITIES_I_RUNNABLE_H

#include "units.h" // for units::time::second_t

namespace thrifty::entities
{

struct IRunnable
{
    virtual void Update(units::time::second_t dt) noexcept = 0;

    IRunnable() = default;
    IRunnable(const IRunnable &other) = default;
    IRunnable(IRunnable &&other) = default;
    auto operator=(const IRunnable &other) -> IRunnable & = default;
    auto operator=(IRunnable &&other) -> IRunnable & = default;
    virtual ~IRunnable() = default;
};

} // namespace thrifty::entities

#endif // THRIFTY_ENTITIES_I_RUNNABLE_H
