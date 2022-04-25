#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cassert>
#include "point.h"


class Triangle
{
public:
    Triangle() {}
    Triangle(Point A,Point B,Point C): A(A),B(B),C(C) { assert(A.dim()==B.dim()); assert(A.dim()==C.dim()); }

    inline int dim() { assert(A.dim()==B.dim()); assert(A.dim()==C.dim()); return A.dim(); }

    void input(int dim, const char* label=nullptr);
    void output(const char* label=nullptr);

    double S();
    bool isPointInside(const Point& p); // точка внутри треугольника?

    void plane(double& a, double& b, double& c, double& d); // определяет уравнение плоскости 3D
    // уравнение плоскости: a*x+b*y+c*z=d

    Point A,B,C;
};

#endif // TRIANGLE_H
