#include "Rectangle.hpp"
#include <cmath>



    Rectangle::Rectangle():
    min_{Vec2{1.0f,1.0f}},
    max_{Vec2{0.0f,0.0f}},
    color_{Color{0.0f}}
    {}

    Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color):
    min_{min}, max_{max}, color_{color}
    {}
    Rectangle::Rectangle(Vec2 const& min, Vec2 const& max):
    min_{min}, max_{max}
    {}

    Vec2 Rectangle::get_max()const{
        return this->max_;
    }
    Vec2 Rectangle::get_min()const{
        return this->min_;
    }

   Color Rectangle::get_color()const{
        return color_;
    }

    float Rectangle::circumference()const{
        float U = 2*(max_.x_)-(min_.x_)+2*(max_.y_)-(min_.y_);
        return U;
    }

    void Rectangle::draw(Window const& win)const
{
    win.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, color_.r_, color_.g_, color_.b_);
    win.draw_line(min_.x_, min_.y_, max_.x_, min_.y_, color_.r_, color_.g_, color_.b_);
    win.draw_line(max_.x_, min_.y_, max_.x_, max_.y_, color_.r_, color_.g_, color_.b_);
    win.draw_line(min_.x_, max_.y_, max_.x_, max_.y_, color_.r_, color_.g_, color_.b_);
}
    void Rectangle::draw(Window const& win, Color const& color_)const
{
    win.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, color_.r_, color_.g_, color_.b_);
    win.draw_line(min_.x_, min_.y_, max_.x_, min_.y_, color_.r_, color_.g_, color_.b_);
    win.draw_line(max_.x_, min_.y_, max_.x_, max_.y_, color_.r_, color_.g_, color_.b_);
    win.draw_line(min_.x_, max_.y_, max_.x_, max_.y_, color_.r_, color_.g_, color_.b_);
}

bool Rectangle::is_inside(Vec2 const& point) const
{
	int temp = 0;
    if (get_min().x_ <= point.x_ && point.x_<= get_max().x_ && get_min().y_ <= point.y_ && point.y_ <= get_max().y_)
    {
      	temp += 1; 
    }
    
    if(temp == 0)
    {
        return false;
    }
    else
    {
        return true;
	}
    }
