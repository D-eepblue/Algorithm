#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>

using namespace std;
using ull = unsigned long long;

string digital_logic;
int K, M;
unordered_map<ull, int> umap;

int main() {
    cin >> digital_logic;
    cin >> K >> M;

    ull key = 0;
    int j = 0;

    for (int i = 0; i < K; i++) {
        if (digital_logic[K - 1 - i] == '1') key += pow(2, i);
    }

    umap[key]++;

    for (int i = K; i < digital_logic.length(); i++) {
        if (digital_logic[j] == '1') key -= pow(2, K - 1);
        key *= 2;
        if (digital_logic[i] == '1') key += 1;
        umap[key]++;
        j++;
    }

    int ret = 0;

    for (auto& kv : umap) {
        if (kv.second >= M) {
            ret = 1;
            break;
        }
    }

    cout << ret;
    

    return 0;
}
