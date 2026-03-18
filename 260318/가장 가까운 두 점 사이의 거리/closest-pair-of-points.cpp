#include <iostream>
#include <math.h>

using namespace std;

int n;
int x[100], y[100];
int dist = 0x7fff'ffff;
int ret = 0x7fff'ffff;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int x1 = x[i], x2 = x[j];
            int y1 = y[i], y2 = y[j];
            int d = abs(x1 - x2) + abs(y1 - y2);
            if (dist > d) {
                dist = d;
                ret = pow(x1 - x2, 2) + pow(y1 - y2, 2);
            }
        }
    }

    cout << ret;

    return 0;
}