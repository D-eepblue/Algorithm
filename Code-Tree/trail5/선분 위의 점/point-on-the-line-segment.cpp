#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m;
int points[100000];
int s, e;

int lbound(int target) {
    int left = 0, right = n - 1;
    int max_idx = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (points[mid] <= target) {
            left = mid + 1;
            max_idx = max(max_idx, mid);
        }
        else {
            right = mid - 1;
        }
    }
    return max_idx;
}

int ubound(int target) {
    int left = 0, right = n - 1;
    int max_idx = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (points[mid] < target) {
            left = mid + 1;
            max_idx = max(max_idx, mid);
        }
        else {
            right = mid - 1;
        }
    }
    return max_idx;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points, points + n);

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        int e_cnt = lbound(e);
        int s_cnt = ubound(s);
        int val = e_cnt - s_cnt;
        cout << val << "\n";
    }

    return 0;
}