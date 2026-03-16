#include <iostream>

using namespace std;

int N, H, T;
int arr[100];

int main() {
    cin >> N >> H >> T;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int cost = 1 << 30;

    for (int start = 0; start <= N - T; start++) {
        int c = 0;
        for (int i = start; i < start + T; i++) {
            c += abs(H - arr[i]);
        }
        cost = min(cost, c);
    }

    cout << cost;

    return 0;
}