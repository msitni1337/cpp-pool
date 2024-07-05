#pragma once
#include "Fixed.hpp"

class Point
{
private:
    const Fixed x, y;

public:
    Point();
    Point(float const x, float const y);
    Point(const Point& p);
    Point& operator=(const Point& p);
    ~Point();
    const Fixed& get_x() const;
    const Fixed& get_y() const;
    bool operator==(const Point& rhs) const;
};

std::ostream &operator<<(std::ostream &out, const Point &rhs);