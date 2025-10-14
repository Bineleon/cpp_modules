#include "Point.hpp"

// Aire triangle ABC = (1/2) | [x a (y b - y c ) + x b (y c - y a ) + x c (y a - y b )] |

Fixed area(Point const a, Point const b, Point const c)
{
    Fixed res = (
        a.getX() * (b.getY() - c.getY()) +
        b.getX() * (c.getY() - a.getY()) +
        c.getX() * (a.getY() - b.getY())
    ) / Fixed(2);

    return res < Fixed(0) ? res * Fixed(-1) : res;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABP = area(a, b, point);
    Fixed areaCPA = area(c, point, a);
    Fixed areaPBC = area(point, b, c);
    Fixed areaABC = area(a, b, c);
    Fixed epsilon(0.01f);

    if (areaABP == Fixed(0) || areaCPA == Fixed(0) || areaPBC == Fixed(0))
        return false;
    Fixed total = areaABP + areaCPA + areaPBC;
    Fixed diff = total - areaABC;
    if (diff < Fixed(0)) diff = diff * Fixed(-1);
    return (diff < epsilon);
}
