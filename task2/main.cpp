#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double EPSILON = 1e-6;

int main() {
	ifstream in1("file1.txt");
    double x0 = 0, y0 = 0, R = 0, x, y, r;
    if (in1.is_open()) {
        in1 >> x0 >> y0 >> R;
        cout << x0 << " "s << y0 << " "s << R << endl;
    }
    in1.close();
    ifstream in2("file2.txt");
    if (in2.is_open()) {
        while (in2 >> x >> y) {
            cout << x << " "s << y << endl;
            r = sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
            if (abs(r - R) < EPSILON) {
                cout << 0 << endl;
            }
            else if (r < R) {
                cout << 1 << endl;
            }
            else {
                cout << 2 << endl;
            }
        }
    }
    in2.close();
    return 0;
}