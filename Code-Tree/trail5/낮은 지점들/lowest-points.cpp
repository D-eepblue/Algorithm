#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, x, y;
unordered_map<int, vector<int>> umap;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        umap[x].push_back(y);
    }

    long long ret = 0;

    for (auto kv : umap) {
        int min_val = 2'111'111'111;
        for (int i : kv.second) {
            min_val = min(min_val, i);
        }
        ret += min_val;
    }

    cout << ret;

    return 0;
}