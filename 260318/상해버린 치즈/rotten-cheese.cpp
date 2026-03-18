#include <iostream>

using namespace std;

int N, M, D, S;
int p, m, t;
int sp, st;
bool xCheese[1001];
int eat[1001][1001];

int main() {
    cin >> N >> M >> D >> S;

    for (int i = 0; i < D; i++) {
        cin >> p >> m >> t;
        eat[p][m] = t;
    }

    for (int i = 0; i < S; i++) {
        cin >> sp >> st;

        for (int chNum = 1; chNum <= M; chNum++) {
            if (eat[sp][chNum] <= st && eat[sp][chNum] != 0) {
                xCheese[chNum] = true;
            }
        }
    }

    int cnt = 0;

    for (int chNum = 1; chNum <= M; chNum++) {
        if (!xCheese[chNum]) continue;
        for (int pNum = 1; pNum <= N; pNum++) {
            if (eat[pNum][chNum] != 0) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}