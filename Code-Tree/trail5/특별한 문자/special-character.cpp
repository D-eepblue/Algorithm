#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string str;
unordered_map<char, int> umap;
vector<char> v;
int idx[26];

int main() {
    cin >> str;

    int i = 0;

    for (char c : str) {
        umap[c]++;
        idx[c - 'a'] = i++;
    }

    for (auto kv : umap) {
        if (kv.second == 1) {
            v.push_back(kv.first);
        }
    }

    if (v.size() == 0) {
        cout << "None";
        return 0;
    }

    char ret = 'a';
    int loc = 1000000;

    for (char c : v) {
        if (loc > idx[c - 'a']) {
            loc = idx[c - 'a'];
            ret = c;
        }
    }

    cout << ret;

    return 0;
}
