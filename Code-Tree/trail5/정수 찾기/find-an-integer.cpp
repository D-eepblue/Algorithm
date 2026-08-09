#include <iostream>
#include <unordered_set>

using namespace std;

int n, m, v;
int arr[100'000];
unordered_set<int> uset;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        uset.insert(v);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i ++) {
        if (uset.find(arr[i]) == uset.end()) {
            cout << "0\n";
        }
        else cout << "1\n";
    }

    return 0;
}
