#include <iostream>

using namespace std;

int n;
int a[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ret = 0;

    for (int k = 2; k <= 99; k++) {
        int cnt = 0;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff1 = abs(k - a[i]);
                int diff2 = abs(k - a[j]);
                if (diff1 == diff2) {
                    cnt++;
                }
            }
        }

        ret = max(ret, cnt);
    }

    cout << ret;

    return 0;
}