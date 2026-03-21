#include <iostream>

using namespace std;

int n;
int h[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int ret = 0;

    for (int height = 1; height <= 1000; height++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] - height <= 0) continue;
            while (h[i] - height > 0) i++;
            cnt++;
        }
        ret = max(ret, cnt);
    }
    cout << ret;

    return 0;
}