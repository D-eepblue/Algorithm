#include <iostream>
#include <math.h>

using namespace std;

int n;
int a[10], b[10], c[10];

bool check(int tgt, int src, int cnt1, int cnt2) {
    int ret1 = 0, ret2 = 0, tmp = src;

    for (int i = 2; i >= 0; i--) {
        int digit1 = tgt / pow(10, i);
        for (int j = 2; j >= 0; j--) {
            int digit2 = src / pow(10, j);
            if (digit1 == digit2) {
                if (i == j) ret1++;
                else ret2++;
            }
            src -= digit2 * pow(10, j);
        }
        tgt -= digit1 * pow(10, i );
        src = tmp;
    }

    return ret1 == cnt1 && ret2 == cnt2;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    int ret = 0;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i == j) continue;
            for (int k = 1; k <= 9; k++) {
                if (i == k || j == k) continue;
                bool flag = true;
                for (int idx = 0; idx < n; idx++) {
                    int tgt = i * 100 + j * 10 + k;
                    if (!check(tgt, a[idx], b[idx], c[idx])) {
                        flag = false;
                        break;
                    }
                }
                if (flag) ret++;
            }
        }
    }

    cout << ret;

    return 0;
}