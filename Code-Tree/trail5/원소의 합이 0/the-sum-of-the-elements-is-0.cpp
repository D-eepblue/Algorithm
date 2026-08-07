#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int A[5000];
int B[5000];
int C[5000];
int D[5000];

unordered_map<int, int> abMap;
unordered_map<int, int> cdMap;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++) cin >> C[i];
    for (int i = 0; i < n; i++) cin >> D[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int abkey = A[i] + B[j];
            int cdkey = C[i] + D[j];
            abMap[abkey]++;
            cdMap[cdkey]++;
        }
    }

    int ret = 0;

    for (auto kv : abMap) {
        int key = kv.first;
        int val = kv.second;

        if (cdMap.count(-key)) {
            ret += val * cdMap[-key];
        }
    }

    cout << ret;
    return 0;
}
