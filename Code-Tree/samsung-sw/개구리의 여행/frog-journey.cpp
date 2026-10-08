#include <iostream>
#include <queue>

using namespace std;

struct pqItem {
    int row;
    int col;
    int jump;
    int time;

    bool operator<(const pqItem& r) const {
        return time > r.time;
    }
};

constexpr int MAX_N = 51;
constexpr int INF = 1e9;

int N, Q, r1, c1, r2, c2;
char grid[MAX_N][MAX_N];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int cost[MAX_N][MAX_N][6];
priority_queue<pqItem> pq;

bool canGo(int row, int col) {
    if (grid[row][col] != '.') return false;
    return row > 0 && row <= N && col > 0 && col <= N;
}

bool canGo2(int sr, int sc, int er, int ec, int d) {
    while (sr != er || sc != ec) {
        sr += dr[d];
        sc += dc[d];

        if (grid[sr][sc] == '#') {
            return false;
        }
    }
    return true;
}

int dijkstra(int sr, int sc, int er, int ec) {
    // inital
    pq = {};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= 5; k++) {
                cost[i][j][k] = INF;
            }
        }
    }

    pq.push(pqItem{ sr, sc, 1, 0 });

    for (int j = 1; j <= 5; j++) {
        cost[sr][sc][j] = 0;
    }

    while (!pq.empty()) {
        pqItem top = pq.top();
        pq.pop();

        if (cost[top.row][top.col][top.jump] > top.time) continue;
        if (top.row == er && top.col == ec) return top.time;

        for (int d = 0; d < 4; d++) {
            for (int j = 1; j <= 5; j++) {
                int nr = top.row + dr[d] * j;
                int nc = top.col + dc[d] * j;

                if (canGo(nr, nc) && canGo2(top.row, top.col, nr, nc, d)) {
                    int ntime = top.time + 1;

                    // 점프력 변화에 따른 시간 증가
                    if (top.jump > j) { // 감소한 경우
                        ntime += 1;
                    }
                    else if (top.jump < j) { // 증가한 경우
                        for (int i = top.jump + 1; i <= j; i++) {
                            ntime += (i * i);
                        }
                    }

                    if (cost[nr][nc][j] > ntime) {
                        cost[nr][nc][j] = ntime;
                        pq.push(pqItem{ nr, nc, j, ntime });
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> Q;

    while (Q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        int ret = dijkstra(r1, c1, r2, c2);
        cout << ret << "\n";
    }

    return 0;
}