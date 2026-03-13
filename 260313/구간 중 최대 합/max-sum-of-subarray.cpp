#include <iostream>

using namespace std;

int n, k;
int arr[101];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int s = 0;
    for (int i = 0; i < k; i++) s += arr[i];
    
    int ret = s;
    
    for (int j = k; j < n; j++) {
        s -= arr[j - k];
        s += arr[j];
        ret = max(ret, s);
    }

    cout << ret;

    return 0;
}