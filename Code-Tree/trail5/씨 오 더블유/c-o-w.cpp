#include <iostream>
#include <string>

using namespace std;

constexpr int MAX_N = 100005;

int n;
string word;
int C[MAX_N], W[MAX_N];

int main() {
    cin >> n;
    cin >> word;

    C[0] = word[0] == 'C' ? 1 : 0;
    W[n-1] = word[n-1] == 'W' ? 1 : 0;

    for (int i = 1; i < n; i++) {
        C[i] = word[i] == 'C' ? 1 : 0;
        C[i] += C[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        W[i] = word[i] == 'W' ? 1 : 0;
        W[i] += W[i + 1];
    }

    long long ret = 0;

    for (int i = 1; i < n - 1; i++) {
        if (word[i] == 'O') {
            long long cnt = C[i - 1] * W[i + 1];
            ret += cnt;
        }
    }

    cout << ret;

    return 0;
}