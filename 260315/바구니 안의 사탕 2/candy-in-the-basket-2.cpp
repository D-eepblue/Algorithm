#include <iostream>

using namespace std;

int N, K;
int candy, pos;
int road[101];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> candy >> pos;
        road[pos] = candy;
    }

    int sum = 0;
    pos = K;

    for (int i = 0; i <= pos + K; i++) {
        sum += road[i];
    }
    
    int ret = sum;

    while (pos++ <= 100 - K) {
        sum -= road[pos - K - 1];
        sum += road[pos + K];
        ret = max(ret, sum);
    }
    cout << ret;

    return 0;
}