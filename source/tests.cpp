#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"
#include "mat2.hpp"
#include <cmath>
#include <iostream>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Color.hpp"
#include "window.hpp"

TEST_CASE ("der default konstruktor belegt die member mit 0.0f" , "Vec2" )
{ 
  Vec2 v{};
  REQUIRE (v.x_ == 0.0f );
  REQUIRE (v.y_ == 0.0f );
}

TEST_CASE ("man kann explizit die koordinaten als parameter übergeben" , "Vec2" )
{
  Vec2 v{3.0f, 5.0f};
  Vec2 u{7.0f, 4.9f};
  REQUIRE(u.x_ == 7.0f);
  REQUIRE(u.y_ == 4.9f);
  REQUIRE(v.x_ == 3.0f);
  REQUIRE(v.y_ == 5.0f);
}

TEST_CASE("it should support the += operator", "[operators]")
{
   Vec2 u{0.0f, 1.0f};
   Vec2 v{1.0f, 0.0f};
   Vec2 t{7.5f, 4.3f};
   t += v;
   u += v;
   REQUIRE(u.x_ == 1.0f);
   REQUIRE(u.y_ == 1.0f);
   REQUIRE(t.x_ == 8.5f);
   REQUIRE(t.y_ == 4.3f);
}

TEST_CASE("it should support the -= operator", "[operators]")
{
  Vec2 u{2.0f, 2.0f};
  Vec2 v{1.0f, 1.0f};
  Vec2 t{2.5f, 5.5f};
  u -= v;
  t -=v;
  REQUIRE(u.x_ == 1.0f);
  REQUIRE(u.y_ == 1.0f);
  REQUIRE(t.x_ == 1.5f);
  REQUIRE(t.y_ == 4.5f);
}

TEST_CASE("it should support the *= operator", "[operators]")
{
  Vec2 u{2.0f, 2.0f};
  Vec2 v{2.5f, 2.5f};
  float s = 1.0f;
  float t = 5.0f;
  u *= s;
  v *= t;
  REQUIRE(u.x_ == 2.0f);
  REQUIRE(u.y_ == 2.0f);
  REQUIRE(v.x_ == 12.5f);
  REQUIRE(v.y_ == 12.5f);
}

TEST_CASE("it should support the /= operator", "[operators]")
{
  Vec2 u{10.0f, 6.0f};
  Vec2 t{5.0f, 2.0f};
  float s = 5.0f;
  float v = 2.0f;
  u /= v;
  t /= s;
  REQUIRE(u.x_ == 5.0f);
  REQUIRE(u.y_ == 3.0f);
  REQUIRE(t.x_ == 1.0f);
  REQUIRE(t.y_ == 0.4f);
}

TEST_CASE("it should support the + operator", "[operators]")
{
  Vec2 u{10.0f, 6.0f};
  Vec2 v{3.0f, 8.0f};
  Vec2 t{5.0f, 4.0f};
  Vec2 b = t + u;
  Vec2 a = u + v;
  REQUIRE(a.x_ == 13.0f);
  REQUIRE(a.y_ == 14.0f);
  REQUIRE(b.x_ == 15.0f);
  REQUIRE(b.y_ == 10.0f);
}
TEST_CASE("it should support the - operator", "[operators]")
{
  Vec2 u{7.0f, 4.0f};
  Vec2 v{2.0f, 3.0f};
  Vec2 t{5.0f, 4.0f};
  Vec2 b = t - u;
  Vec2 a = u - v;
  REQUIRE(a.x_ == 5.0f);
  REQUIRE(a.y_ == 1.0f);
  REQUIRE(b.x_ == -2.0f);
  REQUIRE(b.y_ == 0.0f);
}

TEST_CASE("it should support the * operator", "[operators]")
{
  Vec2 u{8.0f, 4.0f};
  Vec2 v{10.0f,20.0f};
  float t=5;
  float s=2;
  Vec2 a = u * s;
  Vec2 b = v * t;
  REQUIRE(a.x_ == 16.0f);
  REQUIRE(a.y_ == 8.0f);
  REQUIRE(b.x_ == 50.0f);
  REQUIRE(b.y_ == 100.0f);
}
TEST_CASE("it should support the / operator", "[operators]")
{
  Vec2 u{6.0f, 30.0f};
  Vec2 r{20.0f, 10.0f};
  float s=2;
  float t=5;
  Vec2 a = u / s;
  Vec2 b = r / t;
  REQUIRE(a.x_ == 3.0f);
  REQUIRE(a.y_ == 15.0f);
  REQUIRE(b.x_ == 4.0f);
  REQUIRE(b.y_ == 2.0f);
}

TEST_CASE("it should support the * Operator", "[operators]")
{
  float s=5;
  float t=8;
  Vec2 c{1.0f, 2.0f};
  Vec2 u{2.0f, 3.0f};
  Vec2 a = s * u;
  Vec2 d = c * t;
  REQUIRE(a.x_ == 10.0f);
  REQUIRE(a.y_ == 15.0f);
  REQUIRE(d.x_ == 8.0f);
  REQUIRE(d.y_ == 16.0f);
}

TEST_CASE("2x2 matrix multiplication Einheitsmatrix", "[operators]")
{
  Mat2 a{};
  Mat2 b{-8.0f, 4.0f, 2.0f, 5.0f};
  Mat2 c{8.0f, 10.0f, 4.0f, 9.0f};
  b *=a;
  c *=a;
  REQUIRE(b.x1_ == -8.0f);
  REQUIRE(b.x2_ == 4.0f);
  REQUIRE(b.x3_ == 2.0f);
  REQUIRE(b.x4_ == 5.0f);
  REQUIRE(c.x1_ == 8.0f);
  REQUIRE(c.x2_ == 10.0f);
  REQUIRE(c.x3_ == 4.0f);
  REQUIRE(c.x4_ == 9.0f);
}
TEST_CASE ("2x2 matrix matrix Mulitiplication", "[operators]")
{
  Mat2 a{4.0f, 3.0f, 2.0f, 8.0f};
  Mat2 b{2.0f, 4.0f, 2.0f, 7.0f};
  Mat2 c{4.0f, 2.0f, 8.0f, 7.0f};
  Mat2 d = a * b;
  Mat2 e = a * c;
  REQUIRE(d.x1_ == 14.0f);
  REQUIRE(d.x2_ == 37.0f);
  REQUIRE(d.x3_ == 20.0f);
  REQUIRE(d.x4_ == 64.0f);
  REQUIRE(e.x1_ == 40.0f);
  REQUIRE(e.x2_ == 29.0f);
  REQUIRE(e.x3_ == 72.0f);
  REQUIRE(e.x4_ == 60.0f);
}

TEST_CASE("2x2 determinate", "[det]")
{
  Mat2 a{};
  Mat2 b{1.0f, 2.0f ,3.0f , 4.0f};
  REQUIRE(a.det() == 1.0f);
  REQUIRE(b.det() == -2.0f);
}

TEST_CASE("2x2 matrix mit vektor multiplizieren","[operator]")
{
  Mat2 a{};
  Mat2 b{1.0f, 2.0f, 3.0f, 4.0f};
  Vec2 c{1.0f, 2.0f};
  Vec2 d{2.0f, 4.0f};
  Vec2 e = a * c;
  Vec2 f = b * d;
  REQUIRE(e.x_ == 1.0f);
  REQUIRE(e.y_ == 2.0f);
  REQUIRE(f.x_ == 10.0f);
  REQUIRE(f.y_ == 22.0f);
}

TEST_CASE("2x2 matrix mit vektor multiplizieren_2", "[operator]")
{
  Mat2 a{};
  Mat2 b{1.0f, 3.0f, 50.0f, 30.0f};
  Vec2 c{-1.0f, -1.0f};
  Vec2 d = a * c;
  Vec2 e = b * c;
  REQUIRE(d.x_ == -1.0f);
  REQUIRE(d.y_ == -1.0f);
  REQUIRE(e.x_ == -4.0f);
  REQUIRE(e.y_ == -80.0);
}

TEST_CASE("inverse matrix brechenen" "[inverse]")
{
  
  Mat2 a{1.0f, 0.0f, 1.0f, 1.0f};
  Mat2 b = inverse(a);
  REQUIRE(b.x1_ == 1.0f);
  REQUIRE(b.x2_ == -0.0f);
  REQUIRE(b.x3_ == -1.0f);
  REQUIRE(b.x4_ == 1.0f);
  Mat2 c{2.0f, 4.0f, 1.0f, 3.0f};
  Mat2 d = inverse(c);
  REQUIRE(d.x1_ == 1.5f);
  REQUIRE(d.x2_ == -2.0f);
  REQUIRE(d.x3_ == -0.5f);
  REQUIRE(d.x4_ == 1.0f);
}

TEST_CASE("transponierte matrix", "[transpose]")
{
  Mat2 a{2.0, 5.0f, 3.0f, 1.0f};
  Mat2 b{5.0f, 3.0f, 2.0f, 9.0f};
  Mat2 c = transpose(a);
  Mat2 d = transpose(b);
  REQUIRE(c.x1_ == 2.0f);
  REQUIRE(c.x2_ == 3.0f);
  REQUIRE(c.x3_ == 5.0f);
  REQUIRE(c.x4_ == 1.0f);
  REQUIRE(d.x1_ == 5.0f);
  REQUIRE(d.x2_ == 2.0f);
  REQUIRE(d.x3_ == 3.0f);
  REQUIRE(d.x4_ == 9.0f);
}

TEST_CASE("rotiert matrix", "[make_rotation_mat2]")
{
  
  float a = M_PI;
  Mat2 c = make_rotation_mat2(M_PI/2);
  REQUIRE(c.x1_ == Approx(0.0f));
  REQUIRE(c.x2_ == Approx(-1.0f));
  REQUIRE(c.x3_ == Approx(1.0f));
  REQUIRE(c.x4_ == Approx(0));
}

TEST_CASE("circle test", "Circle")
{
  Circle a(5.0f,Vec2{3.0f, 2.0f},Color{0.0f});
  Vec2 b(20.0f,20.0f);
  REQUIRE(a.get_radius()==5.0f);
  REQUIRE(a.get_color().r_==0.0f);
  REQUIRE(a.get_color().g_==0.0f);
  REQUIRE(a.get_color().b_==0.0f);
  REQUIRE(a.get_center().x_==3.0f);
  REQUIRE(a.get_center().y_==2.0f);
  REQUIRE(a.circumference() == Approx(31.41593f));
  REQUIRE(a.is_inside(b)== false);
}

TEST_CASE("rectangle test","Rectangle")
{
  Rectangle a(Vec2{1.0f, 1.0f}, Vec2{2.0f, 2.0f}, Color{0.0f});
  Vec2 b(20.0f, 20.0f);
  Vec2 c(2.0f, 2.0f);
  REQUIRE(a.get_max().x_ == 2.0f);
  REQUIRE(a.get_max().y_ == 2.0f);
  REQUIRE(a.get_min().x_ == 1.0f);
  REQUIRE(a.get_min().y_ == 1.0f);
  REQUIRE(a.circumference() == 6.0f);
  REQUIRE(a.get_color().r_ == 0.0f);
  REQUIRE(a.get_color().g_ == 0.0f);
  REQUIRE(a.get_color().b_ == 0.0f);
  REQUIRE(a.is_inside(b) == false);
  REQUIRE(a.is_inside(c) == true);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
