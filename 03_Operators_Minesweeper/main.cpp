#include "int2.h"
#include "grid.h"

int main() {
    int2 a(3, 4);
    std::cout << a << std::endl;

    int2 b(2, 3);
    std::cout << b << std::endl;

    int2 c = a + b;        //expected value of c: (x= 5,y= 7)
    std::cout << c << std::endl;

    int2 d = a - c;        //expected value of d: (x=-2,y=-3)
    std::cout << d << std::endl;

    b = d * a;            //expected value of b: (x=-6,y=-12)
    std::cout << b << std::endl;

    int2 e = b / c;        //expected value of e: (x=-1,y=-1)
    std::cout << e << std::endl;

    a.x = 2;            //expected value of a: (x= 2,y= 4)
    std::cout << a << std::endl;

    c *= a;                //expected value of c: (x=10,y=28)
    std::cout << c << std::endl;

    c *= 2;                //expected value of c: (x=20,y=56)
    std::cout << c << std::endl;

    d += a;                //expected value of d: (x= 0,y= 1)
    std::cout << d << std::endl;

    d -= b;                //expected value of d: (x= 6,y=13)
    std::cout << d << std::endl;

    d.y = 6;            //expected value of d: (x= 6,y= 6)
    std::cout << d << std::endl; //expected output: (6|6)

    MinesweeperGrid grid = MinesweeperGrid(10, 20, 0.25f);
    grid.PrintGrid();

}