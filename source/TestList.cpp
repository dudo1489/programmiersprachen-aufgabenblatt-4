#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "aufgabe4.2.hpp"




TEST_CASE("List default test", "List_test")
{
    List<int> list1;
    REQUIRE(list1.empty()==true);
    REQUIRE(list1.size()==0);
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}