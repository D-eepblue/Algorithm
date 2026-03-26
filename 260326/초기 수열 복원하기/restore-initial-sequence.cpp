#include <iostream>

using namespace std;

int n;
int adjacent[1001];

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> adjacent[i];
    }

    for (int first = 1; first <= n; first++) {
        bool check[1001] = { false, };
        int result[1001] = { 0, };
        int idx = 0;
        result[idx++] = first;
        check[first] = true;

        for (int i = 0; i < n - 1; i++) {
            int next = adjacent[i] - result[idx-1];
            if (check[next] || next <= 0) break;
            check[next] = true;
            result[idx++] = next;
        }

        if (idx == n) {
            for (int i = 0; i < n; i++) {
                cout << result[i] << " ";
            }
            break;
        }
    }

    return 0;
}