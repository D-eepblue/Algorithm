#include <iostream>

using namespace std;

int X, Y;

int main() {
    cin >> X >> Y;

    int cnt = 0;

    for (int num = X; num <= Y; num++) {
        int check[10] = { false, };
        if(num >= 1000000) check[num / 1000000]++;
        if(num >= 100000) check[num / 100000 % 10]++;
        if (num >= 10000) check[num / 10000 % 10]++;
        if (num >= 1000) check[num / 1000 % 10]++;
        check[num / 100 % 10]++;
        check[num / 10 % 10]++;
        check[num / 1 % 10]++;

        int checkCnt = 0;
        int minCnt = 30;

        for (int i = 0; i < 10; i++) {
            if (check[i] > 0) {
                checkCnt++;
                minCnt = min(minCnt, check[i]);
            }
        }
        if (checkCnt == 2 && minCnt == 1) cnt++;
    }

    cout << cnt;

    return 0;
}