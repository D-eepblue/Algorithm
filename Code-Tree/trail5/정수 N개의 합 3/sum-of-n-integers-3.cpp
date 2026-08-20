#include <iostream>

using namespace std;

int n, k;
int arr[505][505];
int prefix[505][505];

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];
        }
    }

    int ret = 0;

    for (int row = k; row <= n; row++) {
        for (int col = k; col <= n; col++) {
            int sum = prefix[row][col] - prefix[row - k][col] - prefix[row][col - k] + prefix[row - k][col - k];
            ret = max(ret, sum);
        }
    }

    cout << ret;

    return 0;
}