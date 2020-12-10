#include "doctest/doctest.h"
#include "units.h"
using namespace units::literals; // NOLINT(google-build-using-namespace)

#include "entities/Position.h"

// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
SCENARIO("positions can be added and subtracted")
{
    GIVEN("two positions")
    {
        auto position1 = thrifty::entities::Position{1_m, 1_km, 1_ft, 1_deg, 1_rad, 1_rad};
        auto position2 = thrifty::entities::Position{1_ft, 1_m, 1_cm, 1_rad, 1_deg, 1_rad};

        REQUIRE(position1.x == 1_m);
        REQUIRE(position1.y == 1_km);
        REQUIRE(position1.z == 1_ft);
        REQUIRE(position1.h == 1_deg);
        REQUIRE(position1.p == 1_rad);
        REQUIRE(position1.r == 1_rad);

        REQUIRE(position2.x == 1_ft);
        REQUIRE(position2.y == 1_m);
        REQUIRE(position2.z == 1_cm);
        REQUIRE(position2.h == 1_rad);
        REQUIRE(position2.p == 1_deg);
        REQUIRE(position2.r == 1_rad);

        WHEN("they are added")
        {
            auto position3 = position1 + position2;

            THEN("their dimensions are added")
            {
                CHECK(position3.x == position1.x + position2.x);
                CHECK(position3.y == position1.y + position2.y);
                CHECK(position3.z == position1.z + position2.z);
                CHECK(position3.h == position1.h + position2.h);
                CHECK(position3.p == position1.p + position2.p);
                CHECK(position3.r == position1.r + position2.r);
            }
        }

        WHEN("they are addition assigned")
        {
            auto position3 = thrifty::entities::Position{};
            auto positionCopy = position3;
            position3 += position1;

            THEN("their dimensions are addition assigned")
            {
                CHECK(position3.x == positionCopy.x + position1.x);
                CHECK(position3.y == positionCopy.y + position1.y);
                CHECK(position3.z == positionCopy.z + position1.z);
                CHECK(position3.h == positionCopy.h + position1.h);
                CHECK(position3.p == positionCopy.p + position1.p);
                CHECK(position3.r == positionCopy.r + position1.r);
            }
        }

        WHEN("they are subtracted")
        {
            auto position3 = position1 - position2;

            THEN("their dimensions are subtracted")
            {
                CHECK(position3.x == position1.x - position2.x);
                CHECK(position3.y == position1.y - position2.y);
                CHECK(position3.z == position1.z - position2.z);
                CHECK(position3.h == position1.h - position2.h);
                CHECK(position3.p == position1.p - position2.p);
                CHECK(position3.r == position1.r - position2.r);
            }
        }

        WHEN("they are subtraction assigned")
        {
            auto position3 = thrifty::entities::Position{};
            auto positionCopy = position3;
            position3 -= position1;

            THEN("their dimensions are subtraction assigned")
            {
                CHECK(position3.x == positionCopy.x - position1.x);
                CHECK(position3.y == positionCopy.y - position1.y);
                CHECK(position3.z == positionCopy.z - position1.z);
                CHECK(position3.h == positionCopy.h - position1.h);
                CHECK(position3.p == positionCopy.p - position1.p);
                CHECK(position3.r == positionCopy.r - position1.r);
            }
        }
    }
}

// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
SCENARIO("positions can be multiplied and divided by a factor")
{
    GIVEN("a position and a factor")
    {
        auto position = thrifty::entities::Position{1_m, 1_km, 1_ft, 1_deg, 1_rad, 1_rad};
        auto factor = 2.0;

        REQUIRE(position.x == 1_m);
        REQUIRE(position.y == 1_km);
        REQUIRE(position.z == 1_ft);
        REQUIRE(position.h == 1_deg);
        REQUIRE(position.p == 1_rad);
        REQUIRE(position.r == 1_rad);

        WHEN("they are multiplied")
        {
            auto positionMultiplied = position * factor;

            THEN("the dimensions of the position are multiplied")
            {
                CHECK(positionMultiplied.x == position.x * factor);
                CHECK(positionMultiplied.y == position.y * factor);
                CHECK(positionMultiplied.z == position.z * factor);
                CHECK(positionMultiplied.h == position.h * factor);
                CHECK(positionMultiplied.p == position.p * factor);
                CHECK(positionMultiplied.r == position.r * factor);
            }
        }

        WHEN("they are multiplication assigned")
        {
            auto positionMultiplied = thrifty::entities::Position{};
            auto positionCopy = positionMultiplied;
            positionMultiplied *= factor;

            THEN("the dimensions of the position are multiplication assigned")
            {
                CHECK(positionMultiplied.x == positionCopy.x * factor);
                CHECK(positionMultiplied.y == positionCopy.y * factor);
                CHECK(positionMultiplied.z == positionCopy.z * factor);
                CHECK(positionMultiplied.h == positionCopy.h * factor);
                CHECK(positionMultiplied.p == positionCopy.p * factor);
                CHECK(positionMultiplied.r == positionCopy.r * factor);
            }
        }

        WHEN("they are divided")
        {
            auto positionDivided = position / factor;

            THEN("the dimensions of the position are divided")
            {
                CHECK(positionDivided.x == position.x / factor);
                CHECK(positionDivided.y == position.y / factor);
                CHECK(positionDivided.z == position.z / factor);
                CHECK(positionDivided.h == position.h / factor);
                CHECK(positionDivided.p == position.p / factor);
                CHECK(positionDivided.r == position.r / factor);
            }
        }

        WHEN("they are division assigned")
        {
            auto positionDivided = thrifty::entities::Position{};
            auto positionCopy = positionDivided;
            positionDivided /= factor;

            THEN("the dimensions of the position are multiplication assigned")
            {
                CHECK(positionDivided.x == positionCopy.x / factor);
                CHECK(positionDivided.y == positionCopy.y / factor);
                CHECK(positionDivided.z == positionCopy.z / factor);
                CHECK(positionDivided.h == positionCopy.h / factor);
                CHECK(positionDivided.p == positionCopy.p / factor);
                CHECK(positionDivided.r == positionCopy.r / factor);
            }
        }
    }
}
