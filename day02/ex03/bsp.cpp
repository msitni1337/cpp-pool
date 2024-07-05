#include "Point.hpp"

bool compare_on_line(Point const a, Point const b, Point const c, Point const point)
{
    // y2 - y1  / (x2 - x1) = m
    // cx = y1 - m * x1
    float dx = (a.get_x().toFloat() - b.get_x().toFloat());
    float dy = (a.get_y().toFloat() - b.get_y().toFloat());
    if (dx == 0)
    {
        if (c.get_x() == a.get_x())
            return false;
        if (c.get_x() < a.get_x())
        {
            if (point.get_x() >= a.get_x())
                return false;
        }
        else
        {
            if (point.get_x() <= a.get_x())
                return false;
        }
    }
    else
    {
        Fixed delta(dy / dx);
        if (delta == 0)
        {
            if (c.get_y() == a.get_y())
                return false;
            if (c.get_y() < a.get_y())
            {
                if (point.get_y() >= a.get_y())
                    return false;
            }
            else
            {
                if (point.get_y() <= a.get_y())
                    return false;
            }
        }
        else
        {
            Fixed con(a.get_y() - (delta * a.get_x()));
            Fixed cy(delta * c.get_x() + con);
            if (cy == c.get_y())
                return false;
            Fixed py(delta * point.get_x() + con);
            if (c.get_y() < cy)
            {
                if (point.get_y() >= py)
                    return false;
            }
            else
            {
                if (point.get_y() <= py)
                    return false;
            }
        }
    }
    return true;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    if (a == point || b == point || c == point)
        return false;
    return compare_on_line(a, b, c, point) && compare_on_line(b, c, a, point) && compare_on_line(c, a, b, point);
}