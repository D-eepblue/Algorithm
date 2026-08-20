#include <iostream>

using namespace std;

int n, k;
int arr[1005];
int prefix[1005];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    prefix[1] = arr[1];

    for (int i = 2; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int ret = 0;

    for(int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int val = prefix[i] - prefix[j];
            if (val == k) ret++;
        }
    }

    cout << ret;

    return 0;
}