#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;
using ull = unsigned long long;
using pii = pair<int, int>;
using pui = pair<ull, int>;

int n, m;
int f, t, w;
int A, B;
int adj[1001][1001];
ull dist[1001];
priority_queue<pui> pq;

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> f >> t >> w;
        if (adj[f][t] == 0) adj[f][t] = w;
        else adj[f][t] = min(adj[f][t], w);
        if (adj[t][f] == 0) adj[t][f] = w;
        else adj[t][f] = min(adj[t][f], w);
    }

    cin >> A >> B;

    for (int i = 1; i <= n; i++) dist[i] = ULLONG_MAX;
    dist[A] = 0;
    pq.push({ 0, A });

    while (!pq.empty()) {
        pui top = pq.top();
        pq.pop();

        if (dist[top.second] != -top.first) continue;
        if (top.second == B) break;

        for (int next = 1; next <= n; next++) {
            if (adj[top.second][next] == 0) continue;

            ull cost = -top.first + adj[top.second][next];

            if (dist[next] > cost) {
                dist[next] = cost;
                pq.push({ -cost, next });
            }
        }
    }

    cout << dist[B] << "\n";

    return 0;
}