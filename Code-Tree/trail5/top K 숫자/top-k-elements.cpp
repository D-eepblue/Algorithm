#include <iostream>
#include <set>

using namespace std;

int n, k, v;
set<int> mset;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> v;
        mset.insert(v);
    }

    auto iter = mset.rbegin();

    for (int i = 0; i < k; i++) {
        cout << *iter << " ";
        iter++;
    }

    return 0;
}