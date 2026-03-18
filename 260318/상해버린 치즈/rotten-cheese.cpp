#include <iostream>

using namespace std;

int N, M, D, S;
int p, m, t;
int sick_p, sick_t;
int sickInfo[51];
int eatInfo[51][51];

int main() {
    cin >> N >> M >> D >> S;

    for (int i = 0; i < D; i++) {
        cin >> p >> m >> t;
        eatInfo[p][m] = t;
    }
    
    for (int i = 0; i < S; i++) {
        cin >> sick_p >> sick_t;
        sickInfo[sick_p] = sick_t;

        
    }

    int cnt = 0;
    int cheese = 0;

    // 상한 치즈를 선별
    for (int cNum = 1; cNum <= M; cNum++) {
        int sickCnt = 0;
        for (int pNum = 1; pNum <= N; pNum++) {
            if (eatInfo[pNum][cNum] == 0) continue; // 안먹음
            if (sickInfo[pNum] == 0) continue; // 아프지 않음
            sickCnt++;
        }
        if (cnt < sickCnt) {
            cnt = sickCnt;
            cheese = cNum;
        }
    }

    // 치즈를 먹은 사람 계산
    int ret = 0;
    
    for (int pNum = 1; pNum <= N; pNum++) {
        if (eatInfo[pNum][cheese] != 0) ret++;
    }
    cout << ret;

    return 0;
}
