#include <iostream>
#include <set>

using namespace std;
using pii = pair<int, int>;

const int MAX_N = 100000;
int n, m;
int x, y, k;
set<pii> mset;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        mset.insert(pii{ x, y });
    }

    for (int i = 0; i < m; i++) {
        cin >> k;

        auto iter = mset.lower_bound(pii{ k, 1 });

        if (iter != mset.end()) {
            cout << iter->first << " " << iter->second << "\n";
            mset.erase(iter);
        }
        else {
            cout << "-1 -1\n";
        }
    }

    // Please write your code here.

    return 0;
}
