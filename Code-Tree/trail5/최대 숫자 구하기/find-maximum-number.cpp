#include <iostream>
#include <set>

using namespace std;

int n, m, x;
set<int> mset;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) mset.insert(i);

    for (int i = 0; i < n; i++) {
        cin >> x;
        mset.erase(x);
        cout << *mset.rbegin() << "\n";
    }


    return 0;
}