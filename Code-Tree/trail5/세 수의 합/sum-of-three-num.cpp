#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
int arr[5001];
unordered_map<int, int> umap;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        umap[arr[i]]++;
    }

    int ret = 0;

    for (int i = 0; i < n; i++) {
        umap[arr[i]]--;

        for (int j = 0; j < i; j++) {
            int key = k - arr[i] - arr[j];
            if (umap.count(key) > 0) {
                ret += umap[key];
            }
        }
    }

    cout << ret;

    return 0;
}