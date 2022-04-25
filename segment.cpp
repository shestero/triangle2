#include "segment.h"
#include <math.h>
#include <iostream>
using namespace std;

void Segment::input(int dim, const char* label) {
    if (label!=nullptr) {
        cout << label << ":" << endl;
    }
    A.input(dim,"\tA");
    B.input(dim,"\tB");
}

void Segment::output(const char* label) {
    if (label!=nullptr) {
        cout << label << ":";
    }
    A.output("\tA");
    B.output("\tB");
}

double Segment::len() {
    assert(A.dim()==B.dim());
    double s = 0;
    for (int i=0;i<A.dim(),i<B.dim();i++) {
        double d = A[i]-B[i];
        s += d*d;
    }
    return sqrt(s);
}

vector<double> Segment::vec() {
    assert(A.dim()==B.dim());

    vector<double> dx(dim());
    for (int i=0;i<A.dim();i++) dx[i]=B[i]-A[i];
    return dx;
}
