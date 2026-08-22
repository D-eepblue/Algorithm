#include <iostream>

using namespace std;

constexpr int MAX_N = 100005;

int n;
int arr[100005];
int L[100005], R[100005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    L[0] = arr[0];
    R[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++) {
        L[i] = max(arr[i], L[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        R[i] = max(arr[i], R[i + 1]);
    }

    int ret = 0;

    for (int i = 2; i < n - 2; i++) {
        ret = max(ret, arr[i] + L[i - 2] + R[i + 2]);
    }

    cout << ret;

    return 0;
}