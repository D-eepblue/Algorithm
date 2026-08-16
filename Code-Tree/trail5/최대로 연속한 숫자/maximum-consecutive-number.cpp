#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int n, m, v, ret;
set<int> nset;
set<tuple<int, int, int>> pset;

int main() {
    cin >> n >> m;
    
    nset.insert(-1);
    nset.insert(n + 1);
    pset.insert(make_tuple( n + 1, -1, n + 1 ));
    
    for (int i = 0; i < m; i++) {
        cin >> v;

        nset.insert(v);
        
        auto iter = nset.find(v);
        iter--;

        int st = *iter;
        iter++;
        iter++;
        int ed = *iter;
        
        pset.erase({ ed - st - 1, st, ed });
        pset.insert({ v - st - 1, st, v });
        pset.insert({ ed - v - 1, v, ed });

        tie(ret, ignore, ignore) = *pset.rbegin();
        
        cout << ret << "\n";
    }

    return 0;
}