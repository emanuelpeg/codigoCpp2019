#include <iostream>
#include "map.cpp"

using namespace std;

int main()
{
    Map<int,int> myMap = Map<int,int>();
    myMap.put(1,2);
    myMap.put(2,3);
    myMap.put(4,5);
    cout<< myMap.get(1) << " "<<myMap.get(2) << " "<< myMap.get(4);
    return 0;
}

