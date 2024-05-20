#include <iostream>
#include "Int2.h"
#include "Grid.h"

int main() {
    Grid test3_5 = Grid(3, 5);
    test3_5.Print(); std::cout << std::endl;
    test3_5.SetValueAtIndex(0, true);
    test3_5.SetValueAtIndex(4, true);
    test3_5.SetValueAtLocation(int2(2,2), true);
    test3_5.SetValueAtLocation(int2(3,1), true);
    test3_5.SetValueAtLocation(int2(4,0), true);
    test3_5.Print(); std::cout << std::endl;

    test3_5.SetValueAtIndex(15, true);
    test3_5.SetValueAtLocation(int2(5,0), true);
    test3_5.SetValueAtLocation(int2(0,3), true);

    std::cout << test3_5.GetValueAtIndex(15) << std::endl;
    std::cout << test3_5.GetValueAtLocation(int2(5,0)) << std::endl;
    std::cout << test3_5.GetValueAtLocation(int2(0,3)) << std::endl;

    test3_5.GetLocationFromIndex(15);
    std::cout << test3_5.GetIndexFromLocation(int2(5,0)) << std::endl;
    std::cout << test3_5.GetIndexFromLocation(int2(0,3)) << std::endl;

    std::cout << test3_5.GetWidth() << std::endl;
    std::cout << test3_5.GetHeight() << std::endl;
}
