#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

constexpr int INF = (1 << 30);

int n, m;
int a, b, d;
int dist[100001];
vector<pii> adj[100001];
priority_queue<pii> pq;

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        adj[b].push_back(pii{ a, d });
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[n] = 0;
    pq.push(pii{ n, 0 });

    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();

        if (top.second != dist[top.first]) continue;

        for (auto p : adj[top.first]) {
            int next = p.first;
            int cost = top.second + p.second;

            if (dist[next] > cost) {
                pq.push(pii{ next, cost });
                dist[next] = cost;
            }
        }
    }

    int ret = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] != INF) ret = max(ret, dist[i]);
    }

    cout << ret;

    return 0;
}