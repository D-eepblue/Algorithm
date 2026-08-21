#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int n, q, v, a, b;
int idx = 0;
set<int> mset;
unordered_map<int, int> umap;

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> v;
        mset.insert(v);
    }

    for (int a : mset) {
        umap[a] = idx++;
    }

    for (int i = 0; i < q; i++) {

        cin >> a >> b;
        auto start = mset.lower_bound(a);
        auto end = mset.upper_bound(b);

        if (start == mset.end()) {
            cout << 0 << "\n";
            continue;
        }
        if (end == mset.end()) {
            cout << n - umap[*start] << "\n";
            continue;
        }
        
        cout << umap[*end] - umap[*start] << "\n";
    }

    return 0;
}