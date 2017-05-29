#include "mat2.hpp"
#include "Vec2.hpp"
#include <cmath>
#include <iostream>

Mat2::Mat2():
    x1_{1}, x2_{0}, x3_{0},x4_{1}{

}

Mat2::Mat2(float x1, float x2, float x3, float x4):
    x1_(x1),x2_(x2),x3_(x3),x4_(x4){
}

Mat2& Mat2::operator *=(Mat2 const& m){
    float a =x1_ * m.x1_ + x2_ * m.x3_;
    float b =x1_ * m.x2_ + x2_ * m.x4_;
    float c =x3_ * m.x1_ + x4_ * m.x3_;
    float d =x3_ * m.x2_ + x4_ * m.x4_;
    this ->x1_=a;
    this ->x2_=b;
    this ->x3_=c;
    this ->x4_=d;
    return *this;
}


Mat2 operator *(Mat2 const& m1, Mat2 const& m2){
    return Mat2{
        (m1.x1_ * m2.x1_ + m1.x2_ * m2.x3_),
        (m1.x1_ * m2.x2_ + m1.x2_ * m2.x4_),
        (m1.x3_ * m2.x1_ + m1.x4_ * m2.x3_),
        (m1.x3_ * m2.x2_ + m1.x4_ * m2.x4_)
     };
}
float Mat2::det() const{
    return ((x1_*x4_)-(x2_*x3_));
}

Vec2 operator *(Mat2 const& m, Vec2 const& v){
    return Vec2((m.x1_*v.x_+m.x2_*v.y_),(m.x3_*v.x_+m.x4_*v.y_));
}

Vec2 operator *(Vec2 const& v, Mat2 const& m){
    return Vec2((m.x1_*v.x_+m.x2_*v.y_),(m.x3_*v.x_+m.x4_*v.y_));
}

Mat2 inverse(Mat2 const& m){
    Mat2 mat{};
    if(m.det()==0){
        return m;
    }
    float det = 1/m.det();
    mat.x1_ = det * m.x4_;
    mat.x2_ = det * -m.x2_;
    mat.x3_ = det * -m.x3_;
    mat.x4_ = det * m.x1_;
    //std::cout << mat.x1_ << "\n" << mat.x2_ << "\n"<< mat.x3_ << "\n"<< mat.x4_ << "\n";
    return mat;
}

Mat2 transpose(Mat2 const& m){
    Mat2 mat{};

    float a = m.x1_;
    float b = m.x2_;
    float c = m.x3_;
    float d = m.x4_;
    mat.x1_ = a;
    mat.x2_ = c;
    mat.x3_ = b;
    mat.x4_ = d;

    return mat;
}

Mat2 make_rotation_mat2(float phi){
    Mat2 mat;
    mat.x1_ = cos(phi);
    mat.x2_ = -sin(phi);
    mat.x3_ = sin(phi);
    mat.x4_ = cos(phi);

    return mat;
}