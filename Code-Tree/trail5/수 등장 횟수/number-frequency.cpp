#include<iostream>
#include<unordered_map>

using namespace std;

int N, M, val;
unordered_map<int, int> umap;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> val;
        umap[val]++;
    }

    for (int j = 0; j < M; j++) {
        cin >> val;
        cout << umap[val] << " ";
    }

    return 0;
}