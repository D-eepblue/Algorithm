#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string word;
map<string, int> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        m[word]++;
    }

    for (auto kv : m) {
        cout << kv.first << " " << kv.second << "\n";
    }

    return 0;
}
