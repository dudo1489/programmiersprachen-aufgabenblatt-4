#include "Vec2.hpp"


Vec2::Vec2():
x_(0.0f),y_(0.0f){

}
Vec2::Vec2(float x, float y):
x_(x), y_(y){

}

    Vec2& Vec2::operator +=(Vec2 const& v){
        x_ +=v.x_;
        y_ +=v.y_;
        return *this;
    }

    Vec2& Vec2::operator -=(Vec2 const& v){
        x_ -=v.x_;
        y_ -=v.y_;
        return *this;
    }
    Vec2 & Vec2::operator *=( float s ){
        x_ *=s;
        y_ *=s;
        return *this;
    }
    Vec2 & Vec2::operator /=( float s ){
        x_ /=s;
        y_ /=s;
        return *this;
    }
    
    Vec2 operator +( Vec2 const & u , Vec2 const & v ){
        return Vec2(u.x_+v.x_, u.y_+v.y_);
    }

    Vec2 operator -(Vec2 const& u, Vec2 const& v){
        return Vec2(u.x_-v.x_, u.y_-v.y_);
    }

    Vec2 operator *(Vec2 const& v, float s){
        return Vec2(v.x_*s, v.y_*s);
    }

    Vec2 operator /(Vec2 const& v, float s){
        return Vec2(v.x_/s, v.y_/s);
    }

    Vec2 operator *(float s, Vec2 const& v){
        return Vec2(s*v.x_, s*v.y_);
    }