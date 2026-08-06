#include<iostream>
#include<unordered_map>
#include <string>

using namespace std;

int N;
string str;
unordered_map<string, int> umap;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> str;
        umap[str]++;
    }

    int ret = 0;
    for (auto item : umap) {
        ret = max(ret, item.second);
    }

    cout << ret;

    return 0;
}