#include <iostream>
#include <string>

#include <units.h>

using namespace units::literals;

auto main(int /*argc*/, char ** /*argv*/) -> int
{
    using namespace std::string_literals;

    std::cout << "Hello, Thrifty!"s << std::endl;

    auto len = 3.5_m;
    auto tim = 2_s;
    auto vel = len / tim;
    auto str = units::velocity::to_string(vel);
    const auto *abv = units::abbreviation(vel);

    std::cout << str << std::endl;
    std::cout << abv << std::endl;

    return 0;
}
