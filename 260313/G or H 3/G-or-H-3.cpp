#include <iostream>

using namespace std;

int N, K;
int x; char c;
int score[10001];
int loc[100];

int main() {
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> x >> c;
        if (c == 'G') score[x] = 1;
        else score[x] = 2;
        loc[i] = x;
    }

    int ret = 0;

    for (int i = 0; i < N; i++) {
        int lscore = 0;
        for(int pos = loc[i]; pos <= loc[i] + K; pos++){
            lscore += score[pos];
        }
        ret = max(ret, lscore);
    }

    cout << ret;

    return 0;
}