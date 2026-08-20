#include <iostream>

using namespace std;

int N, Q, A, B, V;
int points[1000004];
int prefix[1000004];

int main() {
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> V;
        points[V] = 1;
    }

    for (int i = 1; i <= 1000000; i++) {
        prefix[i] = prefix[i - 1] + points[i];
    }

    for (int i = 0; i < Q; i++) {
        cin >> A >> B;
        int cnt = prefix[B] - prefix[A - 1];
        cout << cnt << "\n";
    }

    return 0;
}
