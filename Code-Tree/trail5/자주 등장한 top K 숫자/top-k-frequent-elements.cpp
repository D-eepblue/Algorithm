#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, v;
unordered_map<int, int> map1;
vector<int> vec[100001];

int main() {
    freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> v;
        map1[v]++;
    }

    for (auto kv : map1) {
        vec[kv.second].push_back(kv.first);
    }

    for (int i = n; i >= 0 && k != 0; i--) {
        if (vec[i].size() > 0) {
            sort(vec[i].rbegin(), vec[i].rend());
            for (int val : vec[i]) {
                if (k == 0)break;
                cout << val << " ";
                k--;
            }
        }
    }

    return 0;
}