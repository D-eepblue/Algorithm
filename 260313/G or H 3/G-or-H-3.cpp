#include <iostream>

using namespace std;

int N, K;
int x;
char c;
char loc[10001];

int main() {
    cin >> N >> K;

    int start = 1 << 30, end = 0, ret = 0;

    for (int i = 0; i < N; i++) {
        cin >> x >> c;
        loc[x] = c;
        start = min(start, x);
        end = max(end, x);
    }

    for (int i = 1; i <= end; i++) {
        int score = 0;
        for (int j = 0; j <= K; j++) {
            if (loc[i + j] == 'G') score += 1;
            else if (loc[i + j] == 'H') score += 2;
        }
        ret = max(ret, score);
    }

    cout << ret;

    return 0;
}