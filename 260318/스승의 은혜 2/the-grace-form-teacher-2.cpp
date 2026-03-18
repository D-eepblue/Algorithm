#include <iostream>

using namespace std;

int N, B;
int P[1000];
int ret = 0;

int main() {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < N; i++) {
        int cnt = 0;
        int money = B;
        for (int j = 0; j < N; j++) {
            int price = P[j];
            if (i == j) {
                price /= 2;
            }
            if (price > money) {
                break;
            }
            money -= price;
            cnt++;
        }
        ret = max(ret, cnt);
    }

    cout << ret;

    return 0;
}