#include<iostream>
#include<queue>
#include<math.h>

using namespace std;
using pii = pair<int, int>;

constexpr int MAX_N = 31;
constexpr int MAX_K = 51;

struct pqItem {
    int dist, row, col;
    
    bool operator<(const pqItem& r) const {
        if (dist == r.dist) {
            if (row == r.row) return col > r.col;
            return row > r.row;
        }
        return dist > r.dist;
    }
};

struct Robot {
    int row, col;
}robot[MAX_K];

int N, K, L;
int grid[MAX_N][MAX_N];
bool existRobot[MAX_N][MAX_N];

bool inRange(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < N;
}

pii bfs(int row, int col) {
    int dr[4] = { -1, 0, 0, 1 };
    int dc[4] = { 0, -1, 1, 0 };
    bool visited[MAX_N][MAX_N] = { false, };
    queue<pqItem> q;
    priority_queue<pqItem> pq;

    q.push(pqItem{ 0, row, col });

    while (!q.empty()) {
        pqItem cur = q.front();
        q.pop();

        if (visited[cur.row][cur.col]) continue;
        visited[cur.row][cur.col] = true;

        if (grid[cur.row][cur.col] > 0) {
            pq.push(pqItem{cur.dist, cur.row, cur.col });
            continue;
        }

        for (int d = 0; d < 4; d++) {
            int nr = cur.row + dr[d];
            int nc = cur.col + dc[d];

            if (existRobot[nr][nc]) continue;
            if (grid[nr][nc] == -1) continue;
            if (!inRange(nr, nc)) continue;

            q.push(pqItem{ cur.dist + 1,  nr, nc });
        }
    }

    if(pq.empty()) return pii{ -1, -1 };
    return pii{ pq.top().row, pq.top().col };
}

void move() {
    for (int i = 0; i < K; i++) {
        Robot& r = robot[i];
        pii next = bfs(r.row, r.col);
        
        // 이동이 가능한 경우만
        if (next.first != -1 && next.second != -1) {
            existRobot[r.row][r.col] = false;
            r.row = next.first;
            r.col = next.second;
            existRobot[r.row][r.col] = true;
        }
    }
}

void clean() {
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {-1, 0, 1, 0};

    for (int i = 0; i < K; i++) {
        Robot& r = robot[i];

        int dust_sum = 0;

        for (int d = 0; d < 4; d++) {
            int nr = r.row + dr[d];
            int nc = r.col + dc[d];
            
            if (inRange(nr, nc) && grid[nr][nc] > 0) {
                dust_sum += min(20, grid[nr][nc]);
            }
        }

        int ret_dust = 0;
        int ret_dir = 0;

        for (int d = 0; d < 4; d++) {
            int ndust = dust_sum;
            int nr = r.row + dr[d];
            int nc = r.col + dc[d];

            if (inRange(nr, nc) && grid[nr][nc] > 0) {
                ndust -= min(20, grid[nr][nc]);
            }

            if (ndust > ret_dust) {
                ret_dust = ndust;
                ret_dir = d;
            }
        }
        
        // 먼지 지우기
        grid[r.row][r.col] = max(0, grid[r.row][r.col] - 20);

        for (int d = 0; d < 4; d++) {
            if (d == ret_dir) continue;

            int nr = r.row + dr[d];
            int nc = r.col + dc[d];

            if (inRange(nr, nc) && grid[nr][nc] > 0) {
                grid[nr][nc] = max(0, grid[nr][nc] - 20);
            }
        }
    }
}

void accumulate() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] > 0) {
                grid[i][j] += 5;
            }
        }
    }
}

void spread() {
    int clone[MAX_N][MAX_N] = { 0, };
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            // 깨끗한 격자가 아니면 pass
            // 로봇 청소기가 위치한 곳에는 어떻게 처리?
            if (grid[r][c] != 0) {
                clone[r][c] = grid[r][c];
                continue;
            }
                
            int dust = 0;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (inRange(nr, nc) && grid[nr][nc] > 0) {
                    dust += grid[nr][nc];
                }
            }

            int ndust = floor(dust / 10);
            clone[r][c] = ndust;
        }
    }

    // clone -> grid
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            grid[r][c] = clone[r][c];
        }
    }
}

void print() {
    int dust_sum = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] > 0) dust_sum += grid[r][c];
        }
    }

    cout << dust_sum << "\n";
}

int main() {
    cin >> N >> K >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        robot[i] = Robot{ r, c };
        existRobot[r][c] = true;
    }

    while (L--) {
        move();
        clean();
        accumulate();
        spread();
        print();
    }

    return 0;
}