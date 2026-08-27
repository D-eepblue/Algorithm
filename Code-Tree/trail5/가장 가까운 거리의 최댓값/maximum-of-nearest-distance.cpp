#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

constexpr int MAX_N = 100'000;
constexpr int INF = 2e9;

struct pqItem {
    int loc;
    int dist;

    bool operator<(const pqItem& r) const {
        return dist > r.dist;
    }
};

int n, m;
int a, b, c;
int from, to, weight;
vector<pii> adj[MAX_N];
int dist[MAX_N][3];

void dijkstra(int start, int num) {
    priority_queue<pqItem> pq;
    
    for (int i = 0; i <= n; i++) {
        dist[i][num] = INF;
    }

    dist[start][num] = 0;
    pq.push(pqItem{ start, 0 });

    while (!pq.empty()) {
        pqItem top = pq.top();
        pq.pop();

        if (dist[top.loc][num] != top.dist) continue;

        for (auto& next : adj[top.loc]) {
            int nloc = next.first;
            int ncost = top.dist + next.second;

            if (dist[nloc][num] > ncost) {
                dist[nloc][num] = ncost;
                pq.push(pqItem{ nloc, ncost });
            }
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> a >> b >> c;

    for (int i = 0; i < m; i++) {
        cin >> from >> to >> weight;
        adj[from].push_back(pii{ to, weight });
        adj[to].push_back(pii{ from, weight });
    }

    dijkstra(a, 0);
    dijkstra(b, 1);
    dijkstra(c, 2);

    int ret = 0;

    for (int i = 1; i <= n; i++) {
        if (i == a || i == b || i == c) continue;
        int min_dist = min(dist[i][0], min(dist[i][1], dist[i][2]));
        ret = max(ret, min_dist);
    }

    cout << ret;

    return 0;
}
