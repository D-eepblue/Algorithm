#include <iostream>
#include <unordered_map>

using namespace std;
using LL = long long;

int n, k, v;
unordered_map<LL, int> umap;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> v;
        umap[v] ++;
    }

    int ret = 0;

    for(auto kv : umap){
        LL _key = kv.first;
        int _val = kv.second;
        LL nextKey = k - _key;

        if(_val == 0) continue;
        if(umap.count(nextKey) == 0) continue;

        if(_key == nextKey){
            ret += (_val * (_val - 1)) / 2;
        }
        else{
            ret += _val * umap[nextKey];
            umap[nextKey] = 0;
        }
    }

    cout << ret;

    return 0;
}
