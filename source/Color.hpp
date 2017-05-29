#ifndef COLOR_HPP
#define COLOR_HPP


struct Color {
    float r_; 
    float g_;
    float b_;
    
    Color();
    Color(float r, float g, float b);
    Color(float all);
};

#endif