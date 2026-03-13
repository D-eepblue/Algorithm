#include <iostream>
#include <math.h>

using namespace std;

int N, S;
int arr[100];
int total = 0;

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    int ret = 1 << 30;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int val = total - arr[i] - arr[j];
            ret = min(ret, abs(S - val));
        }
    }

    cout << ret;

    return 0;
}