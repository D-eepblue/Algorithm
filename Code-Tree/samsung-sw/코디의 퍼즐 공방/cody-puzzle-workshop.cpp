#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;
using pii = pair<int, int>;

constexpr int MAX_N = 2005;

long long total_score = 0;
int Q, N;
int grid[MAX_N][MAX_N];
int puzzle[MAX_N][MAX_N];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int sparePuzzle[256];
int holeCount[256];

int fourPow(int p) {
    if (p == 0) return 1;
    if (p == 1) return 4;
    if (p == 2) return 16;
    if (p == 3) return 64;
    return 0;
}

int encode_hole(int row, int col) {
    return row * MAX_N + col;
}

pii decode_hole(int val) {
    return pii{ val / MAX_N, val % MAX_N };
}

bool inRange(int row, int col) {
    return row >= 1 && row <= N && col >= 1 && col <= N;
}

int countPattern(int pattern) {
    if (pattern == 1) return 3;
    else if (pattern == 2) return 2;
    else return 1;
}

vector<int> getPattern(int val) {
    vector<int> pattern(4);
    pattern[UP] = (val / fourPow(UP)) % 4;
    pattern[RIGHT] = (val / fourPow(RIGHT)) % 4;
    pattern[DOWN] = (val / fourPow(DOWN)) % 4;
    pattern[LEFT] = (val / fourPow(LEFT)) % 4;
    return pattern;
}

bool checkHole(int row, int col) {
    vector<int> pattern = getPattern(grid[row][col]);

    for (int d = 0; d < 4; d++) {
        if (pattern[d] == 0) return false;
    }
    return puzzle[row][col] == 0;
}

int getHash(int up, int right, int down, int left) {
    int key = 0;
    key += up * fourPow(UP);
    key += right * fourPow(RIGHT);
    key += down * fourPow(DOWN);
    key += left * fourPow(LEFT);
    return key;
}

void init() {
    cin >> N;

    // grid 테두리 부분 설정
    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= N; col++) {
            if (row == 1) grid[row][col] += 2 * fourPow(UP);
            if (col == N) grid[row][col] += 2 * fourPow(RIGHT);
            if (row == N) grid[row][col] += 2 * fourPow(DOWN);
            if (col == 1) grid[row][col] += 2 * fourPow(LEFT);
        }
    }
}

void add() {
    int y, x;
    int pattern[4];

    cin >> y >> x;
    for (int dir = 0; dir < 4; dir++) {
        cin >> pattern[dir];
        pattern[dir]++;
    }

    int hash = getHash(pattern[UP], pattern[RIGHT], pattern[DOWN], pattern[LEFT]);

    // 주변 네방향에 영향
    for (int dir = 0; dir < 4; dir++) {
        int effRow = y + dr[dir];
        int effCol = x + dc[dir];

        if (!inRange(effRow, effCol)) continue;

        int effDir = (dir >= 2) ? dir - 2 : dir + 2;

        grid[effRow][effCol] += countPattern(pattern[dir]) * fourPow(effDir);

        // 구멍을 만든 경우
        if (checkHole(effRow, effCol)) {
            vector<int> effPattern = getPattern(grid[effRow][effCol]);
            int effHash = getHash(effPattern[UP], effPattern[RIGHT], effPattern[DOWN], effPattern[LEFT]);
            holeCount[effHash]++;
            total_score += sparePuzzle[effHash];
        }
    }

    if (checkHole(y, x)) {
        holeCount[hash]--;
        total_score -= sparePuzzle[hash];
    }

    puzzle[y][x] = hash;
}

void remove() {
    int y, x;
    cin >> y >> x;

    vector<int> pattern = getPattern(puzzle[y][x]);

    // 주변 네방향에 영향
    for (int dir = 0; dir < 4; dir++) {
        int effRow = y + dr[dir];
        int effCol = x + dc[dir];

        if (!inRange(effRow, effCol)) continue;

        // 구멍을 없애는 경우
        if (checkHole(effRow, effCol)) {
            vector<int> effPattern = getPattern(grid[effRow][effCol]);
            int effHash = getHash(effPattern[UP], effPattern[RIGHT], effPattern[DOWN], effPattern[LEFT]);
            holeCount[effHash]--;
            total_score -= sparePuzzle[effHash];
        }

        int effDir = (dir >= 2) ? dir - 2 : dir + 2;

        grid[effRow][effCol] -= countPattern(pattern[dir]) * fourPow(effDir)    ;
    }
    puzzle[y][x] = 0;

    int hash = grid[y][x];

    // 구멍을 만든 경우
    if (checkHole(y, x)) {
        holeCount[hash]++;
        total_score += sparePuzzle[hash];
    }
}

void spare() {
    int pattern[4];

    for (int dir = 0; dir < 4; dir++) {
        cin >> pattern[dir];
        pattern[dir]++;
    }

    unordered_set<int> hashes;
    hashes.insert(getHash(pattern[UP], pattern[RIGHT], pattern[DOWN], pattern[LEFT]));
    hashes.insert(getHash(pattern[RIGHT], pattern[DOWN], pattern[LEFT], pattern[UP]));
    hashes.insert(getHash(pattern[DOWN], pattern[LEFT], pattern[UP], pattern[RIGHT]));
    hashes.insert(getHash(pattern[LEFT], pattern[UP], pattern[RIGHT], pattern[DOWN]));

    for (int hash : hashes) {
        sparePuzzle[hash]++;
        total_score += holeCount[hash];
    }
}

long long calculate() {
    return total_score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Q;
    int cmd;

    while (Q--) {
        cin >> cmd;
        switch (cmd)
        {
        case 100:
            init();
            break;
        case 200:
            add();
            break;
        case 300:
            remove();
            break;
        case 400:
            spare();
            break;
        case 500:
            long long ret = calculate();
            cout << ret << "\n";
            break;
        }
    }

    return 0;
}