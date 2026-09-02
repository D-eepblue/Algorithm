#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<set>
#include<tuple>

using namespace std;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

constexpr int MAX_N = 51;

struct cell {
    int row, col, dir;
};

queue<cell> q;
int N, row, col, dir;
int grid[MAX_N][MAX_N]; // 0 = 방문 가능 바다, 1 = 산초, 2 = 방문한 바다
int dr[4][4] = {
    {-1, 0, 0, 1},
    {1, 0, 0, -1},
    {0, 1, -1, 0},
    {0, -1, 1, 0}
};
int dc[4][4] = {
    {0, -1, 1, 0},
    {0, 1, -1, 0},
    {-1, 0, 0, 1},
    {1, 0, 0, -1}
};
int rotateMap[4][4] = {
    {0, 2, 3, 1},
    {1, 3, 2, 0},
    {2, 1, 0, 3},
    {3, 0, 1, 2}
};

// STEP.1 : 인접 탐험
// 우선순위 : 전진 -> 좌 -> 우 -> 후진

// STEP.2 : 가까운 바다로 이동
// 가장 가까운 바다 칸으로 이동
// ㄴ우선순위 : 행 번호↓ -> 열 번호↓
// 최단거리로 이동
// ㄴ우선순위 : 좌 -> 하 -> 우 -> 상

bool CanMove(int row, int col) {
    if (row <= 0 || row > N || col <= 0 || col > N) return false;
    if (grid[row][col] == 1) return false;
    return true;
}

pii FindLocation(int row, int col) {
    set<tii> mset;
    int m_dr[4] = { -1, 0, 0, 1 };
    int m_dc[4] = { 0, -1, 1, 0 };
    bool visited[MAX_N][MAX_N] = { false, };
    queue<tii> q;
    q.push(tii{ 0, row, col });

    while (!q.empty()) {
        tii cur = q.front();
        int cur_row, cur_col, cur_dist;
        tie(cur_dist, cur_row, cur_col) = cur;
        q.pop();

        if (grid[cur_row][cur_col] == 0) mset.insert(cur);
        if (visited[cur_row][cur_col]) continue;
        visited[cur_row][cur_col] = true;

        for (int i = 0; i < 4; i++) {
            int nr = cur_row + m_dr[i];
            int nc = cur_col + m_dc[i];

            if (CanMove(nr, nc)) {
                q.push({ cur_dist + 1, nr, nc});
            }
        }
    }

    if (mset.size() == 0) return pii{ -1, -1 };

    int ret_row, ret_col;
    tie(ignore, ret_row, ret_col) = *mset.begin();

    return pii{ ret_row, ret_col };
}

int GetDirection(int sr, int sc, int tr, int tc) {
    int m_dr[4] = { 0, 1, 0, -1 };
    int m_dc[4] = { -1, 0, 1, 0 };
    int m_dir[4] = { 2, 1, 3, 0 };
    bool visited[MAX_N][MAX_N] = { false, };
    queue<cell> q;
    q.push(cell{ sr, sc, 0 });

    while (!q.empty()) {
        cell cur = q.front();
        q.pop();

        if (cur.row == tr && cur.col == tc) return cur.dir;
        if (visited[cur.row][cur.col]) continue;
        visited[cur.row][cur.col] = true;

        for (int i = 0; i < 4; i++) {
            int nr = cur.row + m_dr[i];
            int nc = cur.col + m_dc[i];

            if (CanMove(nr, nc)) {
                q.push({ nr, nc, m_dir[i] });
            }
        }
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> N >> row >> col >> dir;
    dir -= 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    // dir
    // 상(0) 하(1) 좌(2) 우(3)
    q.push(cell{ row, col, dir });

    while (!q.empty()) {
        cell top = q.front();
        q.pop();

        grid[top.row][top.col] = 2;
        cout << top.row << " " << top.col << "\n";

        if (top.row == 35 && top.col == 18) {
            int debug = 5;
        }

        // 우선순위 : 전진 -> 좌 -> 우 -> 후진
        for (int i = 0; i < 4; i++) {
            int nr = top.row + dr[top.dir][i];
            int nc = top.col + dc[top.dir][i];

            if (CanMove(nr, nc) && grid[nr][nc] == 0) {
                int ndir = rotateMap[top.dir][i];
                q.push(cell{ nr, nc, ndir });
                break;
            }
        }

        // 더이상 이동할 곳이 없는 경우
        if (q.empty()) {
            pii nloc = FindLocation(top.row, top.col);

            // 더이상 찾을 바다가 없음
            if (nloc.first == -1) {
                break;
            }

            int ndir = GetDirection(top.row, top.col, nloc.first, nloc.second);

            q.push(cell{ nloc.first, nloc.second, ndir });
        }
    }

    return 0;
}