#include "Point.hpp"
#include <iomanip>

void drawTriangle(Point const& a, Point const& b, Point const& c, Point const& p)
{
    const int gridSize = 20;

    std::cout << SMCYAN;
    for (int y = gridSize - 1; y >= 0; --y)
    {
        for (int x = 0; x < gridSize; ++x)
        {
            Point current((float)x, (float)y);

            if ((int)a.getX().toFloat() == x && (int)a.getY().toFloat() == y)
                std::cout << "A";
            else if ((int)b.getX().toFloat() == x && (int)b.getY().toFloat() == y)
                std::cout << "B";
            else if ((int)c.getX().toFloat() == x && (int)c.getY().toFloat() == y)
                std::cout << "C";
            else if ((int)p.getX().toFloat() == x && (int)p.getY().toFloat() == y)
                std::cout << "p";
            else if (bsp(a, b, c, current))
                std::cout << ".";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << RESET;
}

int main()
{
    Point a(3, 2);
    Point b(17, 2);
    Point c(10, 15);

    Point p(10.2f, 6.002f);

    drawTriangle(a, b, c, p);

    if (bsp(a, b, c, p))
        std::cout << SMGREEN << "\nThe point is IN the triangle.\n" << RESET << std::endl;
    else
        std::cout << SMRED << "\nThe point is NOT IN the triangle.\n" << RESET << std::endl;
    return 0;
}


/*
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
*/
