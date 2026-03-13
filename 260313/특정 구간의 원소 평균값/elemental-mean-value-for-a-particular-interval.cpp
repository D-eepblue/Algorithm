#include <iostream>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ret = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int val = 0;
            for (int j = i; j < i + len; j++) {
                val += arr[j];
            }
            val /= len;

            for (int j = i; j < i + len; j++) {
                if (val == arr[j]) {
                    ret++;
                    break;
                }
            }
        }
    }

    cout << ret;

    return 0;
}