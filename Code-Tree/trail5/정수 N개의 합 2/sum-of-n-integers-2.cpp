#include <iostream>

using namespace std;

int n, k;
int arr[100000];
int prefix[100000];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    prefix[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = arr[i] + prefix[i - 1];
    }

    int ret = prefix[k - 1];

    for (int i = k; i < n; i++) {
        int val = prefix[i] - prefix[i - k];
        ret = max(ret, val);
    }

    cout << ret;

    return 0;
}