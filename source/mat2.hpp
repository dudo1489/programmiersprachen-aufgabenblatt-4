# ifndef MAT2_HPP
# define MAT2_HPP
#include "Vec2.hpp"
#include <cmath>

struct Mat2{
    Mat2();
    Mat2(float x1_, float x2_, float x3_, float x4_);
    float x1_;
    float x2_;
    float x3_;
    float x4_;
    
    Mat2 & operator *=( Mat2 const & m );

    float det() const;
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);
Vec2 operator*(Mat2 const& m, Vec2 const& v);
Mat2 inverse (Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);
#endif