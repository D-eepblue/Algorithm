#include <iostream>

using namespace std;

int ability[5];
int total = 0;
int ret = 1 << 30;

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> ability[i];
        total += ability[i];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) continue;
            for (int k = 0; k < 5; k++) {
                if (i == k || j == k) continue;
                for (int l = 0; l < 5; l++) {
                    if (i == l || j == l || k == l) continue;
                    int team1 = ability[i] + ability[j];
                    int team2 = ability[k] + ability[l];
                    int team3 = total - team1 - team2;
                    if (team1 == team2 || team2 == team3 || team1 == team3) continue;
                    int mx = max(team1, max(team2, team3));
                    int mn = min(team1, min(team2, team3));
                    int diff = mx - mn;
                    ret = min(ret, diff);
                }
            }
        }
    }

    if (ret == 1 << 30) cout << "-1";
    else cout << ret;

    return 0;
}