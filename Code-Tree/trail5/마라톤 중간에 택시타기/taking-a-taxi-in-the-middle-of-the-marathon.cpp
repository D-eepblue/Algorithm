#include <iostream>

using namespace std;

constexpr int MAX_N = 100005;

int n;
int x[MAX_N], y[MAX_N];
int L[MAX_N], R[MAX_N];

int get_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    L[0] = 0;
    R[n - 1] = 0;

    // L, R 배열 채우기
    for (int i = 1; i < n; i++) {
        L[i] = get_distance(x[i - 1], y[i - 1], x[i], y[i]) + L[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        R[i] = get_distance(x[i + 1], y[i + 1], x[i], y[i]) + R[i + 1];
    }
    
    int ret = (1 << 30);

    for (int i = 1; i < n - 1; i++) {
        int dist = L[i - 1] + R[i + 1] + get_distance(x[i - 1], y[i - 1], x[i + 1], y[i + 1]);
        ret = min(ret, dist);
    }

    cout << ret;

    return 0;
}