#include "doctest/doctest.h"
#include "spdlog/spdlog.h"
#include "units.h"

#include "entities/EntityController.h"
#include "entities/Position.h"
#include "entities/Velocity.h"
#include <type_traits>

SCENARIO("EntityController does not throw exceptions") // NOLINT
{
    thrifty::entities::EntityController::GetLogger()->set_level(spdlog::level::trace);

    GIVEN("An EntityController")
    {
        thrifty::entities::EntityController entityController;

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
        thrifty::entities::EntityController entityController;

        WHEN("it is instantiated")
        {
            THEN("it has no entities")
            {
                REQUIRE(entityController.GetRegistry().size() == 0U);
            }
        }

        WHEN("an entity is created")
        {
            auto entity{entityController.CreateEntity()};

            THEN("it is added to the list of entities")
            {
                REQUIRE(entityController.GetRegistry().size() == 1U);

                AND_THEN("it can be found by its id")
                {
                    REQUIRE(entityController.GetRegistry().entity(entity) == entity);
                }
            }

            THEN("its position and velocity are 0")
            {
                using namespace units::literals;

                auto pos = entityController.GetRegistry().get<thrifty::entities::Position>(entity);
                REQUIRE(pos.x == 0_m);
                REQUIRE(pos.y == 0_m);
                REQUIRE(pos.z == 0_m);
                REQUIRE(pos.h == 0_rad);
                REQUIRE(pos.p == 0_rad);
                REQUIRE(pos.r == 0_rad);

                auto vel = entityController.GetRegistry().get<thrifty::entities::Velocity>(entity);
                REQUIRE(vel.dx == 0_mps);
                REQUIRE(vel.dy == 0_mps);
                REQUIRE(vel.dz == 0_mps);
                REQUIRE(vel.dh == 0_rad_per_s);
                REQUIRE(vel.dp == 0_rad_per_s);
                REQUIRE(vel.dr == 0_rad_per_s);
            }
        }
    }
}
