#ifndef GEOMATH_H
#define GEOMATH_H

#include <math.h>
#include <cassert>

#define esmall   0.0001 // "e-малое"

inline bool toosmall(double v) { return fabs(v)<esmall; } // считаем за ноль

// площадь треугольника по сторонам
inline double geron(double a, double b, double c) {
    const double p2 = (a+b+c)/2;
    double s2 = p2*(p2-a)*(p2-b)*(p2-c);
    assert(s2>=0);
    if (s2<0) s2=0; // на всякий случай от вычислительных ошибок округления
    return sqrt(s2);
}

// Определитель 2x2
inline double det2(double a, double b, double c, double d) {
    return a*d-b*c;
}

#endif // GEOMATH_H
