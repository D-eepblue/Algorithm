#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

constexpr int LIMIT = 2111111111;

int N, K, M;
char dir;
vector<tuple<int, int, int>> v;
unordered_set<int> uset;

int main() {
    cin >> N >> K;

    int loc = 0;

    for (int i = 0; i < N; i++) {
        cin >> M >> dir;

        if (dir == 'L') {
            v.push_back(make_tuple(loc - M, 1, i));
            v.push_back(make_tuple(loc, -1, i));
            loc -= M;
        }
        else {
            v.push_back(make_tuple(loc, 1, i));
            v.push_back(make_tuple(loc + M, -1, i));
            loc += M;
        }
    }

    sort(v.begin(), v.end());

    int s = LIMIT, ret = 0;

    for (int i = 0; i < 2 * N; i++) {
        int point, type, idx;
        tie(point, type, idx) = v[i];

        // 시작점
        if (type == 1) {
            uset.insert(idx);
            if (uset.size() >= K) {
                s = min(s, point);
            }
        }
        else {
            uset.erase(idx);
            if (uset.size() < K && s != LIMIT) {
                ret += point - s;
                s = LIMIT;
            }
        }
    }

    cout << ret;

    return 0;
}
