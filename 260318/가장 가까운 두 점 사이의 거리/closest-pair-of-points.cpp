#include <iostream>
#include <math.h>

using namespace std;

int n;
int x[100], y[100];
int ret = 0x7fff'ffff;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = x[i], x2 = x[j];
            int y1 = y[i], y2 = y[j];
            int dist = pow(x1 - x2, 2) + pow(y1 - y2, 2);
            ret = min(ret, dist);
        }
    }

    cout << ret;

    return 0;
}