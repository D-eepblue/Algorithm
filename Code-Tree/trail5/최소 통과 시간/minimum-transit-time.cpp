#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;
using ull = unsigned long long;

int n, m;
int arr[100000];

bool isPossible(ull time) {
    ull cnt = 0;

    for (int i = 0; i < m; i++) {
        cnt += time / arr[i];
    }

    return cnt >= n;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + m);

    ull left = 0;
    ull right = ULLONG_MAX;
    ull ret = ULLONG_MAX;

    while (left <= right) {
        ull mid = (left + right) / 2;

        if (isPossible(mid)) {
            right = mid - 1;
            ret = min(ret, mid);
        }
        else {
            left = mid + 1;
        }
    }

    cout << ret;

    return 0;
}