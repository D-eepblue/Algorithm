#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t, m, v;
priority_queue<int, vector<int>, greater<>> minq;
priority_queue<int> maxq;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m;
        maxq = {}, minq = {};
        for (int j = 1; j <= m; j++) {
            cin >> v;

            if (maxq.size() <= minq.size())
                maxq.push(v);
            else
                minq.push(v);

            if (minq.size() > 0 && maxq.top() > minq.top()) {
                int mx = maxq.top();
                int mn = minq.top();
                maxq.pop();
                minq.pop();
                maxq.push(mn);
                minq.push(mx);
            }

            if (j % 2 != 0) cout << maxq.top() << " ";
        }
        cout << "\n";
    }

    return 0;
}