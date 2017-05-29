#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>


template<typename T, typename S>
T filter(T const& container, S const& s)
{
    T container_new (container.size());
    auto it = std::copy_if(container.begin(), container.end(), container_new.begin(), s);
    container_new.resize(std::distance(container_new.begin(),it));
    return container_new;
}


bool is_even(int n)
{
     return n%2==0;
}

std::vector<int> v{1,2,3,4,5,6};
std::vector<int> alleven = filter(v, is_even);

TEST_CASE ("test is_even", "[is_even]")
{
    std::vector<int> v{1,2,3,4,5,6};
    std::vector<int> alleven = filter(v, is_even);
    REQUIRE(std::all_of(alleven.begin(), alleven.end(), is_even));
}

int main(int argc, char* argv [])
{
    return Catch::Session().run(argc, argv);
}