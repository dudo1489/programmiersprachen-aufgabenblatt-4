#include "Color.hpp"

Color::Color():
    r_{0.0f}, g_{0.0f}, b_{0.0f}
    {}

Color::Color(float all):
    r_{all}, g_{all}, b_{all}
    {}

Color::Color(float r, float g, float b):
    r_{r}, g_{g}, b_{b}
    {}

