#ifndef CIRCLE_HPP  
#define CIRCLE_HPP

#include "Vec2.hpp"
#include "Color.hpp"
#include <cmath>
#include "window.hpp"
#include "mat2.hpp"

class Circle {
    float r_;
    Vec2 center_;
    Color color_;
public:

    Circle();
    Circle(float r, Vec2 const& center, Color const& color);
    Circle(float r, Vec2 const& center);
    Circle(float r);
    Vec2  get_center()const;
    float get_radius()const;
    Color get_color()const;
    float circumference();
    //void draw(Window const& win)const;
    //void draw(Window const& win, Color const& color_)const;
    bool is_inside(Vec2 const& point) const;
    bool operator < (Circle const& c);
    bool operator > (Circle const& c);
    bool operator == (Circle const& c); 
};

#endif