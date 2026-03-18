#include <iostream>

using namespace std;

int ability[6];
int ret = 1 << 30;
int total = 0;

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> ability[i];
        total += ability[i];
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == j) continue;
            for (int k = 0; k < 6; k++) {
                if (i == k || j == k) continue;
                for (int l = 0; l < 6; l++) {
                    if (i == l || j == l || k == l) continue;
                    int team1 = ability[i] + ability[j];
                    int team2 = ability[k] + ability[l];
                    int team3 = total - team1 - team2;
                    int mx = max(team1, max(team2, team3));
                    int mn = min(team1, min(team2, team3));
                    ret = min(ret, mx - mn);
                }
            }
        }
    }

    cout << ret;

    return 0;
}