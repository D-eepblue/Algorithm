#include <iostream>
#include <unordered_map>

using namespace std;

int n;
string words;
unordered_map<int, int>umap;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words;
        
        int key = 0;
        for (char c : words) {
            key += c;
        }
        umap[key]++;
    }

    int ret = 0;
    
    for (auto kv : umap) {
        ret = max(ret, kv.second);
    }

    cout << ret;

    return 0;
}
