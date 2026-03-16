#include <iostream>

using namespace std;

int ab[6];
int total = 0;

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> ab[i];
        total += ab[i];
    }

    int ret = 1 << 30;

    for(int i = 0; i < 6; i ++){
        for(int j = 0; j < 6; j ++){
            if(i == j) continue;
            for(int k = 0; k < 6; k ++){
                if(j == k || i == k) continue;
                int t1 = ab[i] + ab[j] + ab[k];
                int diff = abs(total - t1 * 2);
                ret = min(ret, diff);
            }
        }
    }

    cout << ret;

    return 0;
}