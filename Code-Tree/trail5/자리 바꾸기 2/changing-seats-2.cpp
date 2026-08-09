#include <iostream>
#include <unordered_set>

#define MAX_N 100'005

using namespace std;

int N, K;
int a[MAX_N], b[MAX_N];
int arr[MAX_N];
unordered_set<int> uset[MAX_N];

int main() {
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        cin >> a[i] >> b[i];
    }

    // inital
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
        uset[i].insert(i);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= K; j++) {
            swap(arr[a[j]], arr[b[j]]);
            uset[arr[a[j]]].insert(a[j]);
            uset[arr[b[j]]].insert(b[j]);
        }
    }

    // output
    for (int i = 1; i <= N; i++) {
        cout << uset[i].size() << "\n";
    }

    return 0;
}