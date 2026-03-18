#include <iostream>

using namespace std;

int N;
int A[100], B[100];
int ret = 0;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < N; i++) {
        bool check[1001] = { false, };
        int wTime = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            for (int t = A[j]; t < B[j]; t++) {
                if (check[t]) continue;
                check[t] = true;
                wTime++;
            }
        }

        ret = max(ret, wTime);
    }

    cout << ret;

    return 0;
}