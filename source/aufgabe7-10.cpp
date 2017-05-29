#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "Circle.hpp"
#include "Vec2.hpp"


TEST_CASE ("vergleich Circle", "[operator]")
{
std::vector<Circle> vector2(20);
for (auto& c : vector2)
{
    c=Circle{(std::rand()%101), {10,10},{0.5}};
}
std::sort(vector2.begin(), vector2.end());
REQUIRE(std::is_sorted(vector2.begin(), vector2.end()));
}

TEST_CASE("lambda vergleich", "[lambda]")
{
    std::vector<Circle> vector1(10);
    for(auto& c : vector1)
    {
        c = Circle{(std::rand()%101), {10,10},{0.5}};
    }
std::sort(vector1.begin(), vector1.end(), [](Circle a, Circle b){return a < b;});
REQUIRE(std::is_sorted(vector1.begin(), vector1.end()));

}


TEST_CASE("lambda add", "[add]")
{
std::vector<int> v1{1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
std::vector<int> v2{9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1};
std::vector<int> v3(9);

std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), [](int a, int b){return a+b;});
REQUIRE(std::all_of(v3.begin(), v3.end(),[](int a){return a == 10;}));
}



int main (int argc, char * argv[])
{
return Catch::Session().run(argc, argv);
}
