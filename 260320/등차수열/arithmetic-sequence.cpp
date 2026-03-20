#include <iostream>

using namespace std;

int n, v;
bool check[101];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v;
        check[v] = true;
    }

    int cnt = 0;

    for (int k = 2; k <= 99; k++) {
        if (check[k]) continue;
        
        int lcnt = 0;

        for (int i = 1; i <= k - 1; i++) {
            if (check[i] && check[2 * k - i]) lcnt++;
        }

        cnt = max(cnt, lcnt);
    }

    cout << cnt;

    return 0;
}