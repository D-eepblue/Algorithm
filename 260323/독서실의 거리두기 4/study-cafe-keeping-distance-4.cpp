#include <iostream>
#include <string>

using namespace std;

int N;
string seat;

int main() {
    cin >> N;
    cin >> seat;

    int len = seat.length();
    int ret = 0;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == j) continue;
            if (seat[i] == '1' || seat[j] == '1') continue;
            seat[i] = '1';
            seat[j] = '1';

            int dist = 1 << 30;
            int val = -1;

            for (int i = 0; i < len; i++) {
                if (seat[i] == '1') {
                    if (val == -1) val = i;
                    else {
                        dist = min(dist, i - val);
                        val = i;
                    }
                }
            }

            ret = max(ret, dist);

            seat[i] = '0';
            seat[j] = '0';
        }
    }

    cout << ret;

    return 0;
}