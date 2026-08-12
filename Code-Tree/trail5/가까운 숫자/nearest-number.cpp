#include <iostream>
#include <set>

using namespace std;

int n, val;
int ret = (1 << 30);
set<int> mset;

int main() {
    cin >> n;

    mset.insert(0);

    for (int i = 0; i < n; i++) {
        cin >> val;
        mset.insert(val);

        auto iter = mset.find(val);
        iter--;
        ret = min(ret, val - *iter);
        iter++;
        iter++;
        if(iter != mset.end())
            ret = min(ret, *iter - val);

        cout << ret << "\n";
    }


    return 0;
}