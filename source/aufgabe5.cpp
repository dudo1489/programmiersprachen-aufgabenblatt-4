#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>

bool is_not_multiple_of_3(unsigned int m)
{
    if(m%3==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}


bool is_multiple_of_3 (unsigned int m)
{
    if(m%3==0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}


TEST_CASE ( "filter alle vielfache von drei", "[ erase ]")
{

std::vector<unsigned int> vector1(100);
for(auto i : vector1)
{
    i = std::rand() %101;
}

vector1.erase(std::remove_if(vector1.begin(), vector1.end(), is_not_multiple_of_3), vector1.end()); 
 
REQUIRE (std::all_of(vector1.begin(), vector1.end(), is_multiple_of_3));
}


int main (int argc, char * argv[])
{
return Catch::Session().run(argc, argv);
}
