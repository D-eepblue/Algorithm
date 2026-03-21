#include <iostream>
#include <string>

using namespace std;

int N;
string seat;

int main() {
    cin >> N;
    cin >> seat;

    int ret = 0;

    for (int x = 0; x < seat.length(); x++) {
        if (seat[x] == '0') {
            seat[x] = '1';
            int dist = 30;
            int lDist = -1;
            for (int i = 0; i < seat.length(); i++) {
                if (seat[i] == '1') {
                    if (lDist != -1) {
                        dist = min(dist, i - lDist);
                    }
                    lDist = i;
                }
            }
            seat[x] = '0';
            ret = max(ret, dist);
        }
    }

    cout << ret;

    return 0;
}