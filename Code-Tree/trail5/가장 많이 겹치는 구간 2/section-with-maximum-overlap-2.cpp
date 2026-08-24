#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, x1, x2;
vector<pii> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        v.push_back(make_pair(x1, 1));
        v.push_back(make_pair(x2, -1));
    }

    sort(v.begin(), v.end());

    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < 2 * n; i++) {
        pii& point = v[i];
        sum += point.second;
        cnt = max(cnt, sum);
    }

    cout << cnt;

    return 0;
}
