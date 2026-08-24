#include <iostream>

using namespace std;

int n;
int x1, x2;
int arr[200001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        arr[x1] += 1;
        arr[x2] -= 1;
    }

    int cnt = 0;
    int sum = 0;

    for (int i = 1; i <= 200000; i++) {
        sum += arr[i];
        cnt = max(cnt, sum);
    }

    cout << cnt;

    return 0;
}