#include <iostream>

using namespace std;

int X, Y;

int main() {
    cin >> X >> Y;

    int cnt = 0;

    for (int num = X; num <= Y; num++) {
        bool check[10] = { false, };
        if(num >= 1000000) check[num / 1000000] = true;
        if(num >= 100000) check[num / 100000 % 10] = true;
        if (num >= 10000) check[num / 10000 % 10] = true;
        if (num >= 1000) check[num / 1000 % 10] = true;
        check[num / 100 % 10] = true;
        check[num / 10 % 10] = true;
        check[num / 1 % 10] = true;

        int checkCnt = 0;

        for (int i = 0; i < 10; i++) {
            if (check[i]) checkCnt++;
        }
        if (checkCnt == 2) cnt++;
    }

    cout << cnt;

    return 0;
}