#include "Circle.hpp"
#include <cmath>
#include "window.hpp"

    Circle::Circle():
    center_{1.0f, 1.0f}, r_{1.0f}, color_{0.0f}
    {}

    Circle::Circle(float r):
        r_{r}, color_{0.0f}, center_{1.0f, 1.0f}
        {}
    

   Circle::Circle (float r, Vec2 const& center, Color const& color):
        r_{r}, center_{center}, color_{color}
        {}

    float Circle::get_radius()const{
        return this-> r_;
    }

    Color Circle::get_color()const{
        return this->color_;
    }

    Vec2 Circle::get_center()const{
        return this->center_;
    }

    float Circle::circumference(){
       float U = 2*M_PI*this->r_;
        return U;
    }

    bool Circle::operator < (Circle const& c)
    {
        return(r_< c.r_);
    }

    bool Circle::operator > (Circle const& c)
    {
        return(r_> c.r_);
    }

    bool Circle::operator == (Circle const& c)
    {
        return(r_== c.r_);
    }
