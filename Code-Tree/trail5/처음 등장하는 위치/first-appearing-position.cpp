#include <iostream>
#include <map>

using namespace std;

int n, v;
map<int, int> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        
        if (m.find(v) == m.end()) {
            m[v] = i + 1;
        }
    }

    for (auto kv : m) {
        cout << kv.first << " " << kv.second << "\n";
    }

    return 0;
}
