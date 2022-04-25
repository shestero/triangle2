#include "triangle.h"
#include "geomath.h"
#include "segment.h"
#include <iostream>
using namespace std;

void Triangle::input(int dim, const char* label) {
    if (label!=nullptr) {
        cout << label << ":" << endl;
    }
    A.input(dim,"\tvertex1");
    B.input(dim,"\tvertex2");
    C.input(dim,"\tvertex3");
}

void Triangle::output(const char* label) {
    if (label!=nullptr) {
        cout << label << ":";
    }
    A.output("\tvertex1");
    B.output("\tvertex2");
    C.output("\tvertex3");
}

double Triangle::S() {
    const double a = Segment(A,B).len();
    const double b = Segment(B,C).len();
    const double c = Segment(A,C).len();
    return geron(a,b,c);
}

bool Triangle::isPointInside(const Point& p) {
    const double s = S();
    const double s1 = Triangle(p,B,C).S();
    const double s2 = Triangle(A,p,C).S();
    const double s3 = Triangle(A,B,p).S();
    return toosmall(s-s1-s2-s3);
}

void Triangle::plane(double& a, double& b, double& c, double& d) { // определяет уравнение плоскости
    assert(dim()==3);
    assert( !toosmall(S()) ); // контроль что треугольник не вырожденный

    // a = det2(y2-y1,y3-y1,z2-z1,z3-z1); // при x-x1
    // b =-det2(x2-x1,x3-x1,z2-z1,z3-z1); // при y-y1
    // c = det2(x2-x1,x3-x1,y2-y1,y3-y1); // при z-z1

    a = det2(B[1]-A[1],C[1]-A[1],B[2]-A[2],C[2]-A[2]); // при x-x1
    b =-det2(B[0]-A[0],C[0]-A[0],B[2]-A[2],C[2]-A[2]); // при y-y1
    c = det2(B[0]-A[0],C[2]-A[0],B[1]-A[1],C[1]-A[1]); // при z-z1

    // TODO: контроль выражденных случаев
    // ...

    // коэффициент при уравнении плоскости треугольника (справа)
    d = a*A[0] + b*A[1] + c*A[2];
    // уравнение плоскости: a*x+b*y+c*z=d
}
