#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
using pii = pair<int, int>;

constexpr int INF = (1 << 30);

int n, m, k;
int a, b, w;
int dist[20001];
vector<pii> adj[20001];
priority_queue<pii> pq;

int main() {
    cin >> n >> m;
    cin >> k;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[k] = 0;
    pq.push(pii{ k, 0 });

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

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
