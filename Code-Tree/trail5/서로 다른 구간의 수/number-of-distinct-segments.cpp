#include <iostream>
#include <unordered_set>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int n, a ,b;
unordered_set<int> seg;
vector<tuple<int, int, int>> v;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(make_tuple(a, 1, i));
        v.push_back(make_tuple(b, -1, i));
    }

    sort(v.begin(), v.end());

    int ret = 0;

    for (int i = 0; i < 2 * n; i++) {
        int point, type, idx;
        tie(point, type, idx) = v[i];

        // 시작점
        if (type == 1) {
            if (seg.empty()) {
                ret++;
            }
            seg.insert(idx);
        }
        // 끝점
        else {
            seg.erase(idx);
        }
    }

    cout << ret;

    return 0;
}
