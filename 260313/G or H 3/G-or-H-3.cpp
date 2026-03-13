#include <iostream>

using namespace std;

int N, K;
int x;
char c;
char loc[10001];

int main() {
    cin >> N >> K;

    int end = 0, ret = 0;

    for (int i = 0; i < N; i++) {
        cin >> x >> c;
        loc[x] = c;
        end = max(end, x);
    }

    end -= K;

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