#ifndef SEGMENT_H
#define SEGMENT_H

#include <cassert>
#include <vector>
#include "point.h"

using namespace std;

class Segment
{
public:
    Segment() {}
    Segment(Point A,Point B): A(A), B(B) { assert(A.dim()==B.dim()); }

    inline int dim() { assert(A.dim()==B.dim()); return A.dim(); }

    void input(int dim, const char* label=nullptr);
    void output(const char* label=nullptr);

    double len();

    // параметрическое уравнение отрезка (вектор отрезка)
    vector<double> vec();

    Point A,B;
};

#endif // SEGMENT_H
