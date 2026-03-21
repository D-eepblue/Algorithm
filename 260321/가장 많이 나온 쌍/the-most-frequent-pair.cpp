#include <iostream>

using namespace std;

int n, m;
int a[100], b[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    int ret = 0;

    for (int x = 1; x <= 10; x++) {
        for (int y = 1; y <= 10; y++) {
            if (x == y) continue;
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (a[i] == x && b[i] == y) cnt++;
                if (a[i] == y && b[i] == x) cnt++;
            }
            ret = max(ret, cnt);
        }
    }

    cout << ret;

    return 0;
}