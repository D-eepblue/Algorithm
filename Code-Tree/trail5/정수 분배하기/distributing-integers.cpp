#include <iostream>

using namespace std;

constexpr int MAX_N = 10'000;

int n, m;
int arr[MAX_N];

bool isPossible(int num) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += arr[i] / num;
    }

    return cnt >= m;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 1;
    int right = 100000;
    int max_num = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (isPossible(mid)) {
            max_num = max(max_num, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << max_num;

    return 0;
}
