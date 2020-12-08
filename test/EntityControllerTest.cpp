#include "doctest/doctest.h"
#include "spdlog/spdlog.h"
#include "units.h"

#include "entities/Acceleration.h"
#include "entities/EntityController.h"
#include "entities/Position.h"
#include "entities/Velocity.h"

using namespace units::literals; // NOLINT(google-build-using-namespace)
using thrifty::entities::Acceleration;
using thrifty::entities::EntityController;
using thrifty::entities::Position;
using thrifty::entities::Velocity;

SCENARIO("EntityController does not throw exceptions") // NOLINT
{
    EntityController::GetLogger()->set_level(spdlog::level::trace);

    GIVEN("An EntityController")
    {
        EntityController entityController;

        WHEN("it is initialized")
        {
            THEN("it does not throw an exception")
            {
                REQUIRE_NOTHROW(entityController.Init());
            }
        }

        WHEN("it is started")
        {
            THEN("it does not throw an exception")
            {
                REQUIRE_NOTHROW(entityController.Start());
            }
        }

        WHEN("it is paused")
        {
            THEN("it does not throw an exception")
            {
                REQUIRE_NOTHROW(entityController.Pause());
            }
        }

        WHEN("it is stopped")
        {
            THEN("it does not throw an exception")
            {
                REQUIRE_NOTHROW(entityController.Stop());
            }
        }
    }
}

SCENARIO("EntityController returns Entities") // NOLINT
{
    GIVEN("An EntityController")
    {
        EntityController entityController;

        WHEN("it is instantiated")
        {
            THEN("it has no entities")
            {
                REQUIRE(entityController.Registry()->size() == 0U);
            }
        }

        WHEN("an entity is created")
        {
            auto entity{entityController.CreateEntity()};

            THEN("it is added to the list of entities")
            {
                REQUIRE(entityController.Registry()->size() == 1U);

                AND_THEN("it can be found by its id")
                {
                    REQUIRE(entityController.Registry()->entity(entity) == entity);
                }
            }

            THEN("its position, velocity, and acceleration are 0")
            {
                auto [pos, vel, acc] = entityController.Registry()->get<Position, Velocity, Acceleration>(entity);

                REQUIRE(pos == Position{});
                REQUIRE(vel == Velocity{});
                REQUIRE(acc == Acceleration{});
            }
        }
    }
}

TEST_CASE("EntityController can update Entities") // NOLINT
{
    EntityController entityController;
    entityController.Init();
    entityController.Start();

    auto entity{entityController.CreateEntity()};

    auto [pos, vel, acc] = entityController.Registry()->get<Position, Velocity, Acceleration>(entity);

    acc.x = 1_mps_sq;

    SUBCASE("updating EntityController updates its entities")
    {
        entityController.Update(1_s);
        REQUIRE(pos == Position{1_m, 0_m, 0_m, 0_rad, 0_rad, 0_rad});
        REQUIRE(vel == Velocity{1_mps, 0_mps, 0_mps, 0_rad_per_s, 0_rad_per_s, 0_rad_per_s});
        REQUIRE(acc == Acceleration{1_mps_sq, 0_mps_sq, 0_mps_sq, 0_rad_per_s_sq, 0_rad_per_s_sq, 0_rad_per_s_sq});

        entityController.Update(1_s);
        REQUIRE(pos == Position{3_m, 0_m, 0_m, 0_rad, 0_rad, 0_rad});
        REQUIRE(vel == Velocity{2_mps, 0_mps, 0_mps, 0_rad_per_s, 0_rad_per_s, 0_rad_per_s});
        REQUIRE(acc == Acceleration{1_mps_sq, 0_mps_sq, 0_mps_sq, 0_rad_per_s_sq, 0_rad_per_s_sq, 0_rad_per_s_sq});

        entityController.Update(1_s);
        REQUIRE(pos == Position{6_m, 0_m, 0_m, 0_rad, 0_rad, 0_rad});
        REQUIRE(vel == Velocity{3_mps, 0_mps, 0_mps, 0_rad_per_s, 0_rad_per_s, 0_rad_per_s});
        REQUIRE(acc == Acceleration{1_mps_sq, 0_mps_sq, 0_mps_sq, 0_rad_per_s_sq, 0_rad_per_s_sq, 0_rad_per_s_sq});
    }
}

TEST_CASE("EntityController can update Entities again") // NOLINT
{
    EntityController entityController;
    entityController.Init();
    entityController.Start();

    auto entity{entityController.CreateEntity()};

    auto [pos, vel, acc] = entityController.Registry()->get<Position, Velocity, Acceleration>(entity);

    constexpr auto velocity{100_kph};
    vel.x = velocity;

    SUBCASE("updating EntityController updates its entities")
    {
        entityController.Update(1_hr);
        REQUIRE(pos == Position{100_km, 0_m, 0_m, 0_rad, 0_rad, 0_rad});
        REQUIRE(vel == Velocity{100_kph, 0_mps, 0_mps, 0_rad_per_s, 0_rad_per_s, 0_rad_per_s});
        REQUIRE(acc == Acceleration{0_mps_sq, 0_mps_sq, 0_mps_sq, 0_rad_per_s_sq, 0_rad_per_s_sq, 0_rad_per_s_sq});
    }
}
