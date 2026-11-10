#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

constexpr int INF = (1 << 30);

struct pqitem {
    int mtime;
    int row, col;

    bool operator<(const pqitem& r) const {
        return mtime > r.mtime;
    }
};

int N, A, B;
char grid[30][30];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int dijkstra(int sr, int sc) {
    int cost[30][30];
    priority_queue<pqitem> pq;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cost[row][col] = INF;
        }
    }

    cost[sr][sc] = 0;
    pq.push(pqitem{0, sr, sc});
    
    while (!pq.empty()) {
        pqitem top = pq.top();
        pq.pop();

        if (cost[top.row][top.col] != top.mtime) continue;

        for (int d = 0; d < 4; d++) {
            int nr = top.row + dr[d];
            int nc = top.col + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

            int ncost = top.mtime;

            if (grid[top.row][top.col] == grid[nr][nc]) ncost += A;
            else ncost += B;

            if (cost[nr][nc] > ncost) {
                cost[nr][nc] = ncost;
                pq.push(pqitem{ ncost, nr, nc });
            }
        }
    }

    int longest = 0;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            longest = max(longest, cost[row][col]);
        }
    }

    return longest;
}

int main() {
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);

    cin >> N >> A >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int ret = 0;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            ret = max(ret, dijkstra(row, col));
        }
    }
    
    cout << ret;

    return 0;
}
