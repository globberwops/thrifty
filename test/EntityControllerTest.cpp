#include "doctest/doctest.h"
#include "spdlog/spdlog.h"
#include "units.h"

#include "entities/Acceleration.h"
#include "entities/EntityController.h"
#include "entities/Position.h"
#include "entities/Velocity.h"

using namespace units::literals; // NOLINT(google-build-using-namespace)
using thrifty::entities::EntityController;

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
                REQUIRE(entityController().size() == 0U);
            }
        }

        WHEN("an entity is created")
        {
            auto entity{entityController.CreateEntity()};

            THEN("it is added to the list of entities")
            {
                REQUIRE(entityController().size() == 1U);

                AND_THEN("it can be found by its id")
                {
                    REQUIRE(entityController().entity(entity) == entity);
                }
            }

            THEN("its position, velocity, and acceleration are 0")
            {
                using thrifty::entities::Acceleration;
                using thrifty::entities::Position;
                using thrifty::entities::Velocity;

                auto [pos, vel, acc] = entityController().get<Position, Velocity, Acceleration>(entity);

                REQUIRE(pos.x == 0_m);
                REQUIRE(pos.y == 0_m);
                REQUIRE(pos.z == 0_m);
                REQUIRE(pos.h == 0_rad);
                REQUIRE(pos.p == 0_rad);
                REQUIRE(pos.r == 0_rad);

                REQUIRE(vel.x == 0_mps);
                REQUIRE(vel.y == 0_mps);
                REQUIRE(vel.z == 0_mps);
                REQUIRE(vel.h == 0_rad_per_s);
                REQUIRE(vel.p == 0_rad_per_s);
                REQUIRE(vel.r == 0_rad_per_s);

                REQUIRE(acc.x == 0_mps_sq);
                REQUIRE(acc.y == 0_mps_sq);
                REQUIRE(acc.z == 0_mps_sq);
                REQUIRE(acc.h == 0_rad_per_s_sq);
                REQUIRE(acc.p == 0_rad_per_s_sq);
                REQUIRE(acc.r == 0_rad_per_s_sq);
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

    using thrifty::entities::Acceleration;
    using thrifty::entities::Position;
    using thrifty::entities::Velocity;

    auto [pos, vel, acc] = entityController().get<Position, Velocity, Acceleration>(entity);

    acc.x = 1_mps_sq;

    SUBCASE("updating EntityController updates its entities")
    {
        entityController.Update(1_s);
        REQUIRE(pos.x == 1_m);
        REQUIRE(pos.y == 0_m);
        REQUIRE(pos.z == 0_m);
        REQUIRE(pos.h == 0_rad);
        REQUIRE(pos.p == 0_rad);
        REQUIRE(pos.r == 0_rad);

        REQUIRE(vel.x == 1_mps);
        REQUIRE(vel.y == 0_mps);
        REQUIRE(vel.z == 0_mps);
        REQUIRE(vel.h == 0_rad_per_s);
        REQUIRE(vel.p == 0_rad_per_s);
        REQUIRE(vel.r == 0_rad_per_s);

        REQUIRE(acc.x == 1_mps_sq);
        REQUIRE(acc.y == 0_mps_sq);
        REQUIRE(acc.z == 0_mps_sq);
        REQUIRE(acc.h == 0_rad_per_s_sq);
        REQUIRE(acc.p == 0_rad_per_s_sq);
        REQUIRE(acc.r == 0_rad_per_s_sq);

        entityController.Update(1_s);
        REQUIRE(pos.x == 3_m);
        REQUIRE(pos.y == 0_m);
        REQUIRE(pos.z == 0_m);
        REQUIRE(pos.h == 0_rad);
        REQUIRE(pos.p == 0_rad);
        REQUIRE(pos.r == 0_rad);

        REQUIRE(vel.x == 2_mps);
        REQUIRE(vel.y == 0_mps);
        REQUIRE(vel.z == 0_mps);
        REQUIRE(vel.h == 0_rad_per_s);
        REQUIRE(vel.p == 0_rad_per_s);
        REQUIRE(vel.r == 0_rad_per_s);

        REQUIRE(acc.x == 1_mps_sq);
        REQUIRE(acc.y == 0_mps_sq);
        REQUIRE(acc.z == 0_mps_sq);
        REQUIRE(acc.h == 0_rad_per_s_sq);
        REQUIRE(acc.p == 0_rad_per_s_sq);
        REQUIRE(acc.r == 0_rad_per_s_sq);

        entityController.Update(1_s);
        REQUIRE(pos.x == 6_m);
        REQUIRE(pos.y == 0_m);
        REQUIRE(pos.z == 0_m);
        REQUIRE(pos.h == 0_rad);
        REQUIRE(pos.p == 0_rad);
        REQUIRE(pos.r == 0_rad);

        REQUIRE(vel.x == 3_mps);
        REQUIRE(vel.y == 0_mps);
        REQUIRE(vel.z == 0_mps);
        REQUIRE(vel.h == 0_rad_per_s);
        REQUIRE(vel.p == 0_rad_per_s);
        REQUIRE(vel.r == 0_rad_per_s);

        REQUIRE(acc.x == 1_mps_sq);
        REQUIRE(acc.y == 0_mps_sq);
        REQUIRE(acc.z == 0_mps_sq);
        REQUIRE(acc.h == 0_rad_per_s_sq);
        REQUIRE(acc.p == 0_rad_per_s_sq);
        REQUIRE(acc.r == 0_rad_per_s_sq);
    }
}

TEST_CASE("EntityController can update Entities again") // NOLINT
{
    EntityController entityController;
    entityController.Init();
    entityController.Start();

    auto entity{entityController.CreateEntity()};

    using thrifty::entities::Acceleration;
    using thrifty::entities::Position;
    using thrifty::entities::Velocity;

    auto [pos, vel, acc] = entityController().get<Position, Velocity, Acceleration>(entity);

    vel.x = 100_kph;

    SUBCASE("updating EntityController updates its entities")
    {
        entityController.Update(1_hr);
        REQUIRE(pos.x == 100_km);
        REQUIRE(pos.y == 0_m);
        REQUIRE(pos.z == 0_m);
        REQUIRE(pos.h == 0_rad);
        REQUIRE(pos.p == 0_rad);
        REQUIRE(pos.r == 0_rad);

        REQUIRE(vel.x == 100_kph);
        REQUIRE(vel.y == 0_mps);
        REQUIRE(vel.z == 0_mps);
        REQUIRE(vel.h == 0_rad_per_s);
        REQUIRE(vel.p == 0_rad_per_s);
        REQUIRE(vel.r == 0_rad_per_s);

        REQUIRE(acc.x == 0_mps_sq);
        REQUIRE(acc.y == 0_mps_sq);
        REQUIRE(acc.z == 0_mps_sq);
        REQUIRE(acc.h == 0_rad_per_s_sq);
        REQUIRE(acc.p == 0_rad_per_s_sq);
        REQUIRE(acc.r == 0_rad_per_s_sq);
    }
}
