#include <iostream>

using namespace std;

int N;
int arr[20][20];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    int ret = 0;

    for (int y1 = 0; y1 < N; y1++) {
        for (int x1 = 0; x1 < N - 2; x1++) {
            int cnt1 = 0;
            cnt1 += arr[y1][x1];
            cnt1 += arr[y1][x1 + 1];
            cnt1 += arr[y1][x1 + 2];

            for (int y2 = 0; y2 < N; y2++) {
                for (int x2 = 0; x2 < N - 2; x2++) {
                    if (y1 == y2 && x2 <= x1 + 2) continue;
                    int cnt2 = 0;
                    cnt2 += arr[y2][x2];
                    cnt2 += arr[y2][x2 + 1];
                    cnt2 += arr[y2][x2 + 2];

                    ret = max(ret, cnt1 + cnt2);
                }
            }
        }
    }
    
    cout << ret;

    return 0;
}