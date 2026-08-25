#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

constexpr int INF = (1 << 30);

int n, m;
int a, b, d;
int dist[1001];
int path[1001];
vector<pii> adj[1001];
priority_queue<pii> pq;

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        adj[a].push_back(pii{ b, d });
        adj[b].push_back(pii{ a, d });
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    cin >> a >> b;

    dist[a] = 0;
    pq.push(pii{ a, 0 });

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
                path[next] = top.first;
            }
        }
    }

    vector<int> route;
    route.push_back(b);

    while (!route.empty()) {
        int vx = route.back();

        if (vx == a) break;

        route.push_back(path[vx]);
    }

    cout << dist[b] << "\n";

    for (auto iter = route.rbegin(); iter != route.rend(); iter++) {
        cout << *iter << " ";
    }


    return 0;
}