#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m;
int arr[200000];

bool isPossible(int dist) {
    int selected_cnt = 1;
    int num = arr[0];

    for (int i = 1; i < n; i++) {
        int d = arr[i] - num;
        if (d >= dist) {
            selected_cnt++;
            num = arr[i];
        }
    }

    return selected_cnt >= m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int left = 0;
    int right = INT_MAX;
    int ret = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (isPossible(mid)) {
            left = mid + 1;
            ret = max(ret, mid);
        }
        else {
            right = mid - 1;
        }
    }

    cout << ret;
    return 0;
}