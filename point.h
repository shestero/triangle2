#ifndef POINT_H
#define POINT_H

#include <vector>
using namespace std;

class Point
{
public:
    Point() {}
    Point(const vector<double>& x): x(x) {}

    inline int dim() { return x.size(); }

    void input(int dim, const char* label=nullptr);
    void output(const char* label=nullptr);

    inline double& operator [](int i) { return x[i]; }

    vector<double> x;
};

#endif // POINT_H
