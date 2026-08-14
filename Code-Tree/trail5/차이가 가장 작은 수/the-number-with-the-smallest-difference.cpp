#include <iostream>
#include <set>

#define MAX_VAL (1 << 30)

using namespace std;

int n, m, v;
set<int> mset;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> v;
        mset.insert(v);
    }

    int ret = MAX_VAL;

    for (auto iter = mset.begin(); iter != mset.end(); iter++) {
        int val = *iter + m;
        auto finditer = mset.lower_bound(val);

        if(finditer != mset.end()){
            ret = min(ret, *finditer - *iter);
        }
    }

    if (ret == MAX_VAL) ret = -1;

    cout << ret;

    return 0;
}
