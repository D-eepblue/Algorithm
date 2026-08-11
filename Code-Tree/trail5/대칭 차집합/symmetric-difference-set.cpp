#include <iostream>
#include <unordered_set>

using namespace std;

int n, m, v;
unordered_set<int> Uset;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> v;
        Uset.insert(v);
    }

    for (int i = 0; i < m; i++){
        cin >> v;
        Uset.insert(v);
    }

    int com_cnt = n + m - Uset.size();
    int ret = n + m - (com_cnt * 2);

    cout << ret;

    return 0;
}
