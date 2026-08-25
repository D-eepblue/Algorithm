#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m;
int f, t, w;
int A, B;
int adj[1001][1001];
priority_queue<pii> pq;
int dist[1001];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> f >> t >> w;
        adj[f][t] = w;
        adj[t][f] = w;
    }

    cin >> A >> B;

    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[B] = 0;
    pq.push({0, B});

    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();

        if (dist[top.second] != -top.first) continue;
        if (top.second == A) break;

        for (int next = 1; next <= n; next++) {
            if (adj[top.second][next] == 0) continue;

            int cost = -top.first + adj[top.second][next];

            if (dist[next] > cost) {
                dist[next] = cost;
                pq.push({ -cost, next });
            }
        }
    }

    cout << dist[A] << "\n";

    int x = A;

    cout << x << " ";

    while (x != B) {
        for (int i = 1; i <= n; i++) {
            if (adj[i][x] == 0) continue;

            if (dist[i] + adj[i][x] == dist[x]) {
                x = i;
                break;
            }
        }
        cout << x << " ";
    }

    return 0;
}