#include <iostream>

using namespace std;

int N;
int x[100], y[100];
int ret = (1 << 31) - 1;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < N; i++) {
        int x1 = 40001, x2 = 0, y1 = 40001, y2 = 0;

        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            x1 = min(x1, x[j]);
            x2 = max(x2, x[j]);
            y1 = min(y1, y[j]);
            y2 = max(y2, y[j]);
        }
        int surf = (x2 - x1) * (y2 - y1);
        ret = min(ret, surf);
    }

    cout << ret;

    return 0;
}