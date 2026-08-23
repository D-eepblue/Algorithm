#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
int n;
int x1, x2;
pair<int, int> seg[MAX_N];
int L[MAX_N], R[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        seg[i] = make_pair(x1, x2);
    }

    sort(seg, seg + n);

    L[0] = seg[0].second;
    for (int i = 1; i < n; i++) {
        L[i] = max(seg[i].second, L[i - 1]);
    }

    R[n - 1] = seg[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
        R[i] = min(seg[i].second, R[i + 1]);
    }

    int ret = 0;

    for (int i = 0; i < n; i++) {
        if (i > 0 && L[i - 1] > seg[i].second) ret++;
        else if (i < n - 1 && R[i + 1] < seg[i].second) ret++;
    }

    cout << n - ret;

    return 0;
}
