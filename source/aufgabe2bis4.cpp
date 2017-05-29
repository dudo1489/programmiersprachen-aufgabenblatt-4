#include <iostream>
#include <list>
#include <array>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <ostream>
#include <set>
#include <map>

int main(){
    
    std::list<unsigned int> list1;
    srand(time(NULL));
    unsigned int v;
    std::vector<unsigned int> vector1;
    
    
    for (int index=0; index <100; index++)
    {
        v = (rand() %101);
        list1.push_back(v);
    }
        
        
    std::copy(list1.begin(), list1.end(),
        std::back_inserter(vector1));
   
    
    int x;
    std::set<int> str(list1.begin(), list1.end());
    for(auto i : str)
    {
    list1.push_back(i);
        for(int j = 0; j<101; ++j)
        {
            if(i == j)
            {
                ++i;
            }
            else
            {
                x=j;
            }
        }
    std::cout<<"not in list "<<x<<"\n";
    }
    std::cout<<str.size()<<" verschiedene Zahlen in der Liste"<<"\n";
    std::cout<<100-str.size()<<" Zahlen sind nicht in der Liste"<<"\n";
    
    
    std::map<unsigned int,unsigned int> map1;
    for(auto& i : list1)
    {
        map1[i] += 1;
    }

    for(auto& i : map1)
    {
        std::cout<<i.first<<":"<<i.second<<"\n";
    }
    //std::cout<<map1.size()<<"\n";

    
}