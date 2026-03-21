#include <iostream>

using namespace std;

int n, k;
int arr[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ret = 1 << 30;

    for (int i = 1; i < n - 1; i++) {
        int key = arr[i];
        int cnt = 0;
        int dist = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > key) cnt++;
            else {
                dist = max(dist, cnt);
                cnt = 0;
            }
        }
        if (dist < k) ret = min(ret, key);
    }

    cout << ret;

    return 0;
}