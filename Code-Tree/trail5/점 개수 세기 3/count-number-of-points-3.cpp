#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

const int MAX_N = 100000;
int n, q, v;
int a, b;
set<int> points;
unordered_map<int, int> umap;

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> v;
        points.insert(v);
    }

    int idx = 0;

    for (auto iter = points.begin(); iter != points.end(); iter++) {
        umap[*iter] = idx++;
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;

        int count = umap[b] - umap[a] + 1;
        cout << count << "\n";
    }

    return 0;
}
