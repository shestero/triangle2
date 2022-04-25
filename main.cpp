#include "geomath.h"
#include "point.h"
#include "segment.h"
#include "triangle.h"
#include <numeric>
#include <iostream>
#include <valarray>
using namespace std;

void getpoint3d(const char* label, double& x, double& y, double& z) {
    cout << label << ":" << endl;
    cin >> x >> y >> z;
}

int main(int argc, char *argv[])
{
    cout << "Tirangle and Segmant" << endl;

    Segment s;
    s.input(3,"Segment");

    Triangle tr;
    tr.input(3,"trianle");

    // контроль что треугольник не вырожденный
    assert( !toosmall(tr.S()) );

    // уравнение плоскости
    double a,b,c,d;
    tr.plane(a,b,c,d);

    // параметрическое уравнение отрезка
    const vector<double> dx = s.vec();
    // система имеет вид: X=dX*t+aX, где X {x,y,z}
    // в случае отрезка 0<=t<=1

    // подставляем в уравнение плоскости:
    // a*(dx*t+ax)+b*(dy*t+ay)+c*(dz*t+az) = d
    // (a*dx+b*dy+c*dz)*t = d - a*ax - b*ay - c*az
    const vector<double> v{a,b,c};
    const double D = inner_product(v.begin(),v.end(),dx.begin(),0); // A*dx+B*dy+C*dz;
    if (toosmall(D)) {
        cout << "no solution {1}" << endl; // треугольник параллелен отрезку
        return 0;
    }

    const double t = (d-inner_product(v.begin(),v.end(),s.A.x.begin(),0))/D;
    if (t<0||t>1) {
        cout << "no solution {2}" << endl; // прямая пересекает плоскость вне отрезка
        return 0;
    }

    //const double x = ax+dx*t;
    //const double y = ay+dy*t;
    //const double z = az+dz*t;

    Point p;
    transform(s.A.x.begin(),s.A.x.end(),dx.begin(),back_inserter(p.x), [t](const double& a,const double& d){return a+d*t;});

    if (!tr.isPointInside(p)) {
        cout << "no solution {3}" << endl; // отрезок пересекает плоскость вне треугольника
        return 0;
    }

    cout.precision(4);
    p.output("Solution");
    cout << endl;

    return 0;
}
