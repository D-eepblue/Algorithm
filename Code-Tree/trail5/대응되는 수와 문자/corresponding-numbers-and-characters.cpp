#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
string instr;
unordered_map<string, string> umap;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> instr;
        umap[instr] = to_string(i);
        umap[to_string(i)] = instr;
    }

    for (int i = 0; i < m; i++) {
        cin >> instr;
        cout << umap[instr] << "\n";
    }

    return 0;
}
