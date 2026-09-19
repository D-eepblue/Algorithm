#include <iostream>

using namespace std;
using ull = unsigned long long;

ull m, a, b;

int bsearch_cnt(ull num) {
    ull left = 1, right = m;
    int cnt = 1;

    while (left <= right) {
        ull mid = (left + right) / 2;
        if (mid == num) break;
        if (mid > num) right = mid - 1;
        else left = mid + 1;
        cnt++;
    }

    return cnt;
}

int main() {
    cin >> m;
    cin >> a >> b;

    int min_cnt = 100'000;
    int max_cnt = 0;

    for (ull i = a; i <= b; i++) {
        int cnt = bsearch_cnt(i);
        min_cnt = min(min_cnt, cnt);
        max_cnt = max(max_cnt, cnt);
    }

    cout << min_cnt << " " << max_cnt;

    return 0;
}