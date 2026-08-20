#include <iostream>

using namespace std;

int N, Q;
int arr[100005];
int prefix[100005][4];
int a, b;

int main() {
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    prefix[1][arr[1]] = 1;

    for (int i = 2; i <= N; i++) {
        prefix[i][1] = prefix[i - 1][1];
        prefix[i][2] = prefix[i - 1][2];
        prefix[i][3] = prefix[i - 1][3];
        prefix[i][arr[i]] += 1;
    }

    for (int i = 0; i < Q; i++) {
        cin >> a >> b;

        int g1 = prefix[b][1] - prefix[a - 1][1];
        int g2 = prefix[b][2] - prefix[a - 1][2];
        int g3 = prefix[b][3] - prefix[a - 1][3];

        printf("%d %d %d\n", g1, g2, g3);
    }

    return 0;
}