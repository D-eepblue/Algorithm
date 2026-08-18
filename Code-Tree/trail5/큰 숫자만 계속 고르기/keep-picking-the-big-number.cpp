#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
priority_queue<int> pq;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> v;
        pq.push(v);
    }

    for (int i = 0; i < m; i++) {
        int val = pq.top();
        pq.pop();
        pq.push(val - 1);
    }

    cout << pq.top();

    return 0;
}