#include <iostream>

using namespace std;

int n, q, a, b;
int arr[100000];
int L[100000], R[100000];

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> arr[i];

    L[0] = arr[0];
    for (int i = 1; i < n; i++) {
        L[i] = max(arr[i], L[i - 1]);
    }

    R[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        R[i] = max(arr[i], R[i + 1]);
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        a -= 1, b -= 1;
        int max_val = max(L[a - 1], R[b + 1]);
        cout << max_val << "\n";
    }

    return 0;
}