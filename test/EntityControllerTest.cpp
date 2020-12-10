#include "doctest/doctest.h"
#include "entt/entt.hpp"
#include "spdlog/spdlog.h"
#include "units.h"

#include "entities/EntityController.h"
#include "units/Units.h"

using namespace units::literals; // NOLINT(google-build-using-namespace)
using thrifty::entities::EntityController;
using thrifty::units::acceleration_sixdof_t;
using thrifty::units::position_sixdof_t;
using thrifty::units::velocity_sixdof_t;

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
                auto [pos, vel, acc] =
                    entityController.Registry()->get<position_sixdof_t, velocity_sixdof_t, acceleration_sixdof_t>(
                        entity);

                REQUIRE(pos == position_sixdof_t{});
                REQUIRE(vel == velocity_sixdof_t{});
                REQUIRE(acc == acceleration_sixdof_t{});
            }
        }
    }
}

TEST_CASE("EntityController can update Entities") // NOLINT
{
    EntityController entityController;

    auto entity{entityController.CreateEntity()};

    auto [pos, vel, acc] =
        entityController.Registry()->get<position_sixdof_t, velocity_sixdof_t, acceleration_sixdof_t>(entity);

    acc.x = 1_mps_sq;

    SUBCASE("updating EntityController updates its entities")
    {
        entityController.Update(1_s, nullptr, ::entt::null);
        REQUIRE(pos == position_sixdof_t{1_m, 0_m, 0_m, 0_rad, 0_rad, 0_rad});
        REQUIRE(vel == velocity_sixdof_t{1_mps, 0_mps, 0_mps, 0_rad_per_s, 0_rad_per_s, 0_rad_per_s});
        REQUIRE(acc ==
                acceleration_sixdof_t{1_mps_sq, 0_mps_sq, 0_mps_sq, 0_rad_per_s_sq, 0_rad_per_s_sq, 0_rad_per_s_sq});

        entityController.Update(1_s, nullptr, ::entt::null);
        REQUIRE(pos == position_sixdof_t{3_m, 0_m, 0_m, 0_rad, 0_rad, 0_rad});
        REQUIRE(vel == velocity_sixdof_t{2_mps, 0_mps, 0_mps, 0_rad_per_s, 0_rad_per_s, 0_rad_per_s});
        REQUIRE(acc ==
                acceleration_sixdof_t{1_mps_sq, 0_mps_sq, 0_mps_sq, 0_rad_per_s_sq, 0_rad_per_s_sq, 0_rad_per_s_sq});

        entityController.Update(1_s, nullptr, ::entt::null);
        REQUIRE(pos == position_sixdof_t{6_m, 0_m, 0_m, 0_rad, 0_rad, 0_rad});
        REQUIRE(vel == velocity_sixdof_t{3_mps, 0_mps, 0_mps, 0_rad_per_s, 0_rad_per_s, 0_rad_per_s});
        REQUIRE(acc ==
                acceleration_sixdof_t{1_mps_sq, 0_mps_sq, 0_mps_sq, 0_rad_per_s_sq, 0_rad_per_s_sq, 0_rad_per_s_sq});
    }
}

TEST_CASE("EntityController can update Entities again") // NOLINT
{
    EntityController entityController;

    auto entity{entityController.CreateEntity()};

    auto [pos, vel, acc] =
        entityController.Registry()->get<position_sixdof_t, velocity_sixdof_t, acceleration_sixdof_t>(entity);

    constexpr auto velocity{100_kph};
    vel.x = velocity;

    SUBCASE("updating EntityController updates its entities")
    {
        entityController.Update(1_hr, nullptr, ::entt::null);
        REQUIRE(pos == position_sixdof_t{100_km, 0_m, 0_m, 0_rad, 0_rad, 0_rad});
        REQUIRE(vel == velocity_sixdof_t{100_kph, 0_mps, 0_mps, 0_rad_per_s, 0_rad_per_s, 0_rad_per_s});
        REQUIRE(acc ==
                acceleration_sixdof_t{0_mps_sq, 0_mps_sq, 0_mps_sq, 0_rad_per_s_sq, 0_rad_per_s_sq, 0_rad_per_s_sq});
    }
}
