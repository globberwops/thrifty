#include "doctest/doctest.h"
#include "spdlog/spdlog.h"

#include "entities/EntityController.h"
#include "entities/IEntity.h"

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
                REQUIRE(entityController.GetEntities().empty());
            }
        }

        WHEN("an entity is created")
        {
            auto entity{entityController.CreateEntity("test")};
            REQUIRE(entity.use_count() == 2U);

            THEN("it is added to the list of entities")
            {
                REQUIRE(entityController.GetEntities().size() == 1U);
                REQUIRE(entityController.GetEntity(entity->GetId()).use_count() == 3U);

                AND_THEN("it can be found by its id")
                {
                    REQUIRE(entityController.GetEntity(entity->GetId()));
                }
            }
        }
    }
}
