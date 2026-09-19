#include <iostream>

using namespace std;

int n, m;
int arr[100000];

int bin_search(int num) {
    int start = 0, end = n;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == num) return mid + 1;

        if (arr[mid] > num) end = mid - 1;
        else start = mid + 1;
    }

    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        int ret = bin_search(x);
        cout << ret << "\n";
    }

    return 0;
}
