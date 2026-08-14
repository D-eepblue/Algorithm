#include <iostream>
#include <set>

using namespace std;

int n, m, v;
int a[100000];
set<int> mset;

int main() {
    cin >> n >> m;

    // intial
    for (int i = 1; i <= m; i++) {
        mset.insert(-i);
    }

    for (int i = 0; i < n; i++) {
        cin >> v;

        auto iter = mset.lower_bound(-v);

        if (iter == mset.end()) {
            break;
        }

        mset.erase(iter);
    }

    cout << m - mset.size();

    return 0;
}