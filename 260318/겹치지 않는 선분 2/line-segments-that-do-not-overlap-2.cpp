#include <iostream>

using namespace std;

int N, cnt = 0;
int x1[100], x2[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x1[i] >> x2[i];
    }

    for (int i = 0; i < N; i++) {
        bool flag = false;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (x1[i] < x1[j] && x2[i] > x2[j]) {
                flag = true;
                break;
            }
            if (x1[i] > x1[j] && x2[i] < x2[j]) {
                flag = true;
                break;
            }
        }
        if (flag) cnt++;
    }

    cout << N - cnt;

    return 0;
}