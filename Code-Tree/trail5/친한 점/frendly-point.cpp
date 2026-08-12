#include <iostream>
#include <set>

using namespace std;

int n, m, x, y;
set<pair<int, int>> mset;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        mset.insert(make_pair(x, y));
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        auto iter = mset.lower_bound(make_pair(x, y));
        if (iter == mset.end()) cout << "-1 -1\n";
        else cout << iter->first << " " << iter->second << "\n";
    }

    return 0;
}