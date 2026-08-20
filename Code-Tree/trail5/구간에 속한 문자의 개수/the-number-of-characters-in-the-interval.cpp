#include <iostream>

using namespace std;

int n, m, k;
char grid[1001][1001];
int prefix[1001][1001][3];

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    prefix[1][1][grid[1][1] - 'a'] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j][0] = prefix[i - 1][j][0] + prefix[i][j - 1][0] - prefix[i - 1][j - 1][0];
            prefix[i][j][1] = prefix[i - 1][j][1] + prefix[i][j - 1][1] - prefix[i - 1][j - 1][1];
            prefix[i][j][2] = prefix[i - 1][j][2] + prefix[i][j - 1][2] - prefix[i - 1][j - 1][2];
            prefix[i][j][grid[i][j] - 'a']++;
        }
    }

    for (int i = 0; i < k; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int a = prefix[r2][c2][0] - prefix[r1 - 1][c2][0] - prefix[r2][c1 - 1][0] + prefix[r1 - 1][c1 - 1][0];
        int b = prefix[r2][c2][1] - prefix[r1 - 1][c2][1] - prefix[r2][c1 - 1][1] + prefix[r1 - 1][c1 - 1][1];
        int c = prefix[r2][c2][2] - prefix[r1 - 1][c2][2] - prefix[r2][c1 - 1][2] + prefix[r1 - 1][c1 - 1][2];

        printf("%d %d %d\n", a, b, c);
    }

    return 0;
}