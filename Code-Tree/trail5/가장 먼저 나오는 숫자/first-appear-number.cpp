#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100000];
int query[100000];

int lbound(int num) {
    int left = 0, right = n;
    int min_idx = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] >= num) {
            right = mid - 1;
            if (arr[mid] == num) min_idx = min(min_idx, mid);
        }
        else {
            left = mid + 1;
        }
    }
    if (min_idx == n) return -1;
    return min_idx + 1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> query[i];
        int ret = lbound(query[i]);
        cout << ret << "\n";
    }

    return 0;
}
