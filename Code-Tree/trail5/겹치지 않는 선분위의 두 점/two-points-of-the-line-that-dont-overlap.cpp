#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll a, b;
int N, M;
vector<pll> segs;

bool isPossible(ll dist) {
    int cnt = 0;
    ll prev = LLONG_MIN;

    for (auto& seg : segs) {
        while (prev + dist <= seg.second) {
            cnt++;
            prev = max(seg.first, prev + dist);
        }
    }

    return cnt >= N;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        segs.push_back({ a,b });
    }

    sort(segs.begin(), segs.end());

    ll left = 0;
    ll right = LLONG_MAX;
    ll ret = 0;

    while (left <= right) {
        ll mid = (left + right) / 2;

        if (isPossible(mid)) {
            left = mid + 1;
            ret = max(ret, mid);
        }
        else {
            right = mid - 1;
        }
    }

    cout << ret;

    return 0;
}
