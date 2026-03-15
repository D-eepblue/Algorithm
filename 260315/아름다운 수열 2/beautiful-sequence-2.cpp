#include <iostream>

using namespace std;

int N, M;
int A[100], B[100];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    int ret = 0;

    for (int i = 0; i < N; i++) {
        bool check[100] = { false, };
        for (int j = i; j < i + M; j++) {
            for (int k = 0; k < M; k++) {
                if (!check[k] && A[j] == B[k]) {
                    check[k] = true;
                    break;
                }
            }
        }
        bool comp = true;
        for (int i = 0; i < M; i++) {
            comp &= check[i];
        }
        if (comp) ret++;
    }

    cout << ret;

    return 0;
}