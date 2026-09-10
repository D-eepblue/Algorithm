#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <vector>
#include <iostream>
#include <math.h>

#define EMPTY   0
#define CORAL   1
#define TURTLE  2
#define VOLCANO 4
#define FOSSIL  8

using namespace std;
using pii = pair<int, int>;

constexpr int INF = (1 << 30);

struct turtle {
    int row, col;
    int state; // 0 = 생존, -1 = 화석, N = 도착한 턴
};

struct volcano {
    int row, col;
    int threshold, cur_val;
};

struct qitem {
    int row, col, dir;
};

int N, M, K;
int grid[21][21];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
vector<turtle> turtles;
vector<volcano> volcanoes;

turtle* findTurtle(int row, int col) {
    for (turtle& t : turtles) {
        if (t.row == row && t.col == col) return &t;
    }
    return nullptr;
}

volcano* findVolcano(int row, int col) {
    for (volcano& t : volcanoes) {
        if (t.row == row && t.col == col) return &t;
    }
    return nullptr;
}

bool CanMove(int row, int col) {
    // 범위를 벗어난 경우
    if (row < 0 || row >= N || col < 0 || col >= N) return false;
    // 산호초거나 화석인 경우
    if (grid[row][col] == CORAL || grid[row][col] == FOSSIL) return false;
    // 다른 거북이가 존재하는 경우
    if ((grid[row][col] & TURTLE) != 0) return false;

    return true;
}

bool CanMove2(int row, int col) {
    // 범위를 벗어난 경우
    if (row < 0 || row >= N || col < 0 || col >= N) return false;
    // 산호초인 경우
    if (grid[row][col] == CORAL) return false;

    return true;
}

void move(turtle& t, int turn) {
    queue<qitem> q;
    bool visited[21][21] = { false, };

    for (int i = 0; i < 4; i++) {
        int r = t.row + dr[i];
        int c = t.col + dc[i];

        if (CanMove(r, c)) {
            q.push(qitem{ r, c, i });
        }
    }

    int ret_dir = -1;

    while (!q.empty()) {
        qitem top = q.front();
        q.pop();

        // 안식처에 도착
        if (top.row == N - 1 && top.col == N - 1) {
            ret_dir = top.dir;
            break;
        }
        if (visited[top.row][top.col]) continue;
        visited[top.row][top.col] = true;

        for (int dir = 0; dir < 4; dir++) {
            int nr = top.row + dr[dir];
            int nc = top.col + dc[dir];

            if (!CanMove(nr, nc)) continue;

            q.push(qitem{ nr, nc, top.dir });
        }
    }

    // 최단경로가 없는 경우
    if (ret_dir == -1) return;
    
    // 거북이 이동
    grid[t.row][t.col] -= TURTLE;
    t.row += dr[ret_dir];
    t.col += dc[ret_dir];

    // 안식처에 도착한 경우
    if (t.row == N - 1 && t.col == N - 1) {
        t.state = turn;
    }
    else {
        grid[t.row][t.col] += TURTLE;
    }
}

int main() {
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int r, c, p;

    for (int i = 0; i < M; i++) {
        cin >> r >> c;
        turtles.push_back(turtle{ r, c, 0 });
        grid[r][c] = TURTLE;
    }

    for (int i = 0; i < K; i++) {
        cin >> r >> c >> p;
        volcanoes.push_back(volcano{ r, c, p, 0 });
        grid[r][c] = VOLCANO;
    }

    int cur_turn = 1, max_turn = 100;
    queue<volcano> q;

    while (cur_turn <= max_turn) {
        // step1
        for (turtle& t : turtles) {
            if(t.state == 0) move(t, cur_turn);
        }
        // step2
        for (volcano& v : volcanoes) {
            v.cur_val += 10;
            if (v.cur_val >= v.threshold) q.push(v);
        }

        // step3
        int heatmap[21][21] = { 0, };
        bool eruption[21][21] = { false };

        while (!q.empty()) {
            volcano top = q.front();
            q.pop();

            heatmap[top.row][top.col] += top.threshold;
            eruption[top.row][top.col] = true;

            // 4방향 열기 전파
            for (int i = 0; i < 4; i++) {
                int heat = floor(top.threshold / 2);
                int nr = top.row + dr[i];
                int nc = top.col + dc[i];

                while (heat != 0 && CanMove2(nr, nc)) {
                    heatmap[nr][nc] += heat;

                    if ((grid[nr][nc] & VOLCANO) && !eruption[nr][nc]) {
                        volcano *v = findVolcano(nr, nc);

                        // 연쇄 분출
                        if (v->cur_val + heatmap[nr][nc] >= v->threshold) {
                            q.push(volcano{v->row, v->col, v->threshold, v->cur_val});
                            eruption[nr][nc] = true;
                        }
                    }

                    nr += dr[i];
                    nc += dc[i];
                    heat = floor(heat / 2);
                }
            }
        }

        // 거북이 화석화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((grid[i][j] & TURTLE) && heatmap[i][j] >= 20) {
                    grid[i][j] = FOSSIL;
                    turtle* t = findTurtle(i, j);
                    t->state = -1;
                }
            }
        }

        // step4
        for (volcano& v : volcanoes) {
            if (v.cur_val >= v.threshold) v.cur_val = 0;
        }

        cur_turn++;
    }

    for (turtle t : turtles) {
        if (t.state == 0) cout << -1 << "\n";
        else cout << t.state << "\n";
    }

    return 0;
}