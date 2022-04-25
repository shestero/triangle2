#include "point.h"

#include <iostream>
using namespace std;

void Point::input(int dim, const char* label) {
    x.resize(dim);
    if (label!=nullptr) {
        cout << label << ":" << endl;
    }
    for (int i=0;i<dim;i++) {
        cin >> x[i];
    }
}

void Point::output(const char* label) {
    if (label!=nullptr) {
        cout << label << ":" << endl;
    }
    for (int i=0;i<dim();i++) {
        cout << "\tx[" << i << "]=" << x[i] << endl;
    }
}
