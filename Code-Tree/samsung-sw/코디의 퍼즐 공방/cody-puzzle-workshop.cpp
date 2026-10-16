#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 퍼즐의 모양은 위·오른쪽·아래·왼쪽 변(0 오목, 1 직선, 2 볼록)을 3진수 네 자리로 본 정수(0~80)로 바꿔서 다룹니다.
const int SHAPES = 81;
const int STRAIGHT = 1;

// 위, 오른쪽, 아래, 왼쪽 순서의 이웃 방향입니다.
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int n;

// piece[r][c] : (r, c) 칸에 배치된 퍼즐의 모양 번호입니다. 빈칸이면 -1입니다.
vector<vector<int>> piece;

// kind[x] : 모양 x를 0~3번 돌려 얻는 모양 가운데 가장 작은 번호입니다.
// kind 값이 같은 두 모양은 서로 돌려서 만들 수 있으므로 같은 종류로 봅니다.
int kind[SHAPES];

// spare[k] : 종류 k인 스페어 퍼즐의 개수입니다.
// holeCount[k] : 들어가야 할 모양이 종류 k인 구멍의 개수입니다.
long long spare[SHAPES], holeCount[SHAPES];

// total : 현재 점수입니다. 항상 (종류 k마다 spare[k] × holeCount[k]의 합)과 같도록 유지합니다.
long long total = 0;

// 네 변의 모양을 읽어 모양 번호로 바꿉니다.
int readShape() {
    int x = 0;
    for (int i = 0; i < 4; i++) {
        int v;
        cin >> v;
        x = x * 3 + v;
    }
    return x;
}

// 시계 방향으로 90도 돌린 모양을 구합니다.
// abcd를 돌리면 dabc가 되므로, 마지막 자리를 맨 앞으로 옮기면 됩니다.
int rotate(int x) {
    return (x % 3) * 27 + x / 3;
}

// 모양 x의 d번 변(0 위, 1 오른쪽, 2 아래, 3 왼쪽)을 구합니다.
int sideOf(int x, int d) {
    for (int i = d; i < 3; i++) x /= 3;
    return x % 3;
}

// 변 v와 맞물리는 변을 구합니다. 오목은 볼록, 볼록은 오목, 직선은 직선과 맞물립니다.
int partner(int v) {
    return 2 - v;
}

// 빈칸 (r, c)가 구멍이면 그 칸에 들어가야 할 모양 번호를, 구멍이 아니면 -1을 돌려줍니다.
// 테두리 쪽 변은 직선이어야 하고, 퍼즐이 있는 이웃 쪽 변은 그 퍼즐과 맞물려야 합니다.
// 비어 있는 이웃이 하나라도 있으면 구멍이 아닙니다.
int holeShape(int r, int c) {
    int x = 0;
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d], v;
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) v = STRAIGHT;
        else if (piece[nr][nc] < 0) return -1;
        else v = partner(sideOf(piece[nr][nc], (d + 2) % 4));
        x = x * 3 + v;
    }
    return x;
}

// (r, c)가 구멍이면, 그 구멍의 종류에 해당하는 holeCount와 total에 sign(+1 또는 -1)만큼 반영합니다.
void apply(int r, int c, int sign) {
    if (r < 0 || r >= n || c < 0 || c >= n || piece[r][c] >= 0) return;
    int x = holeShape(r, c);
    if (x < 0) return;
    holeCount[kind[x]] += sign;
    total += sign * spare[kind[x]];
}

// (r, c) 칸의 상태를 v로 바꿉니다.
// 구멍 여부와 모양이 바뀔 수 있는 칸은 이 칸과 상하좌우 이웃 칸뿐이므로,
// 다섯 칸의 기여를 빼고 상태를 바꾼 뒤 다시 더합니다.
void change(int r, int c, int v) {
    for (int d = 0; d < 4; d++) apply(r + dr[d], c + dc[d], -1);
    apply(r, c, -1);
    piece[r][c] = v;
    for (int d = 0; d < 4; d++) apply(r + dr[d], c + dc[d], 1);
    apply(r, c, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 모양마다 종류를 미리 구해 둡니다.
    for (int x = 0; x < SHAPES; x++) {
        int best = x, y = x;
        for (int t = 0; t < 3; t++) {
            y = rotate(y);
            if (y < best) best = y;
        }
        kind[x] = best;
    }

    int q;
    cin >> q;
    string out;
    while (q--) {
        int type;
        cin >> type;
        if (type == 100) {
            // 퍼즐 판 준비: 모든 칸이 빈칸인 N×N 판을 만듭니다.
            // N ≥ 3이면 모든 칸에 비어 있는 이웃이 있으므로 처음에는 구멍이 없습니다.
            cin >> n;
            piece.assign(n, vector<int>(n, -1));
        } else if (type == 200) {
            // 퍼즐 배치: (y, x)에 주어진 모양의 퍼즐을 그대로 놓습니다.
            int y, x;
            cin >> y >> x;
            change(y - 1, x - 1, readShape());
        } else if (type == 300) {
            // 퍼즐 제거: (y, x)의 퍼즐을 치웁니다.
            int y, x;
            cin >> y >> x;
            change(y - 1, x - 1, -1);
        } else if (type == 400) {
            // 스페어 퍼즐 추가: 같은 종류의 구멍마다 점수가 1씩 늘어납니다.
            int k = kind[readShape()];
            spare[k]++;
            total += holeCount[k];
        } else {
            // 퍼즐 맞추기: 유지해 온 점수를 그대로 출력합니다.
            out += to_string(total) + '\n';
        }
    }
    cout << out;
    return 0;
}

