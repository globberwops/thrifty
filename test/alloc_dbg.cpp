#include <iostream>

namespace
{
auto noAllocs = 0U; // NOLINT
} // namespace

auto operator new(std::size_t n) -> void *
{
    std::cout << "[No. allocs: " << ++noAllocs << "]" << std::endl;
    return malloc(n); // NOLINT
}

void operator delete(void *p) noexcept
{
    std::cout << "[No. allocs: " << --noAllocs << "]" << std::endl;
    free(p); // NOLINT
}
