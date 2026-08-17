#include <iostream>
#include <set>

using namespace std;

int n, m, v;
set<int> mset;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> v;
        mset.insert(-v);
    }

    for (int i = 0; i < m; i++) {
        cin >> v;
        auto iter = mset.lower_bound(-v);
        if (iter == mset.end()) {
            cout << "-1\n";
        }
        else {
            cout << -(*iter) << "\n";
            mset.erase(iter);
        }
    }

    return 0;
}