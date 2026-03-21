#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[1000];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    int ret = 0;


    for (int i = 0; i < N; i++) {
        int key = arr[i];
        int cnt = 1;
        for (int j = i + 1; j < N; j++) {
            if (abs(key - arr[j]) > K) break;
            cnt++;
        }
        ret = max(ret, cnt);
    }

    cout << ret;

    return 0;
}