#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using pii = pair<int, int>;

int N, s, e;
vector<pii> segments;

bool isPossible(int dist) {
    int prePoint = segments[0].first;

    for (int i = 1; i < segments.size(); i++) {
        int point = prePoint + dist;
        if (segments[i].first <= point && point <= segments[i].second) {
            prePoint = point;
        }
        else if (point <= segments[i].first) {
            prePoint = segments[i].first;
        }
        else return false;
    }

    return true;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        segments.push_back(pii{ s, e });
    }

    sort(segments.begin(), segments.end());

    int left = 1, right = 1000000000;
    int ret = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;

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