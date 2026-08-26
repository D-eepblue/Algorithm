#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;
using ull = unsigned long long;

using pii = pair<int, int>;
using pui = pair<ull, int>;

constexpr int MAX_N = 1005;

struct pqItem {
    ull cost;
    int time;
    int station;
    int bus_num;

    bool operator<(const pqItem& r) const {
        if (cost == r.cost) return time > r.time;
        return cost > r.cost;
    }
};

int A, B, N;
int cnt;
int bus_fare[MAX_N];
vector<pii> adj[MAX_N];
pui dist[MAX_N][MAX_N];
priority_queue<pqItem> pq;

int main() {
    cin >> A >> B >> N;

    for (int i = 1; i <= N; i++) {
        cin >> bus_fare[i] >> cnt;
        int stop;
        vector<int> bus_stop;
        for (int j = 0; j < cnt; j++) {
            cin >> stop;
            bus_stop.push_back(stop);
        }
        for (int j = 0; j < cnt - 1; j++) {
            adj[bus_stop[j]].push_back(pii{ bus_stop[j + 1], i });
        }
    }

    for (int i = 1; i < MAX_N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j].first = ULLONG_MAX;
            dist[i][j].second = INT_MAX;
        }
    }

    dist[A][0].first = 0; // cost
    dist[A][0].second = 0; // time

    pq.push(pqItem{0, 0, A, 0});

    while (!pq.empty()) {
        pqItem top = pq.top();
        pq.pop();

        if (dist[top.station][top.bus_num].first != top.cost ||
            dist[top.station][top.bus_num].second != top.time) continue;

        if (top.station == B) {
            cout << top.cost << " " << top.time << "\n";
            return 0;
        }

        for (auto& next : adj[top.station]) {
            ull next_cost = top.cost;
            int next_time = top.time + 1;
            
            // 버스가 바뀌는 경우
            if (top.bus_num != next.second) {
                next_cost += bus_fare[next.second];
            }

            if (dist[next.first][next.second] > pui{next_cost, next_time}) {
                dist[next.first][next.second] = pui{next_cost, next_time};
                pq.push(pqItem{ next_cost, next_time, next.first, next.second });
            }
        }
    }
    
    cout << -1 << " " << -1 << "\n";

    return 0;
}