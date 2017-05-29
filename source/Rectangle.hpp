#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Vec2.hpp"
#include "Color.hpp"
#include <cmath>
#include "window.hpp"

class Rectangle{
    Vec2 min_;
    Vec2 max_;
    Color color_;

    public:
    Rectangle();
    Rectangle(Vec2 const& min, Vec2 const& max, Color const& color);
    Rectangle(Vec2 const& min, Vec2 const& max);
    Vec2 get_min()const;
    Vec2 get_max()const;
    float circumference()const;
    Color get_color()const;
    void draw(Window const& win)const;
    void draw(Window const& win, Color const& color_)const;
    bool is_inside(Vec2 const& point)const;
};

#endif