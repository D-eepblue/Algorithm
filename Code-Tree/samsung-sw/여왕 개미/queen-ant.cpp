#include <iostream>
#include <set>

#define INIT 100
#define ADD 200
#define REMOVE 300
#define SEARCH 400

using namespace std;

constexpr int LIMIT = 1e9;
constexpr int MAX_HOUSE = 20005;

int Q, CMD, N, x;
int house_idx = 1;
int houseInfo[MAX_HOUSE];
set<int> houseLoc;

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        houseInfo[house_idx++] = x;
        houseLoc.insert(x);
    }
}

void add() {
    cin >> x;
    houseInfo[house_idx++] = x;
    houseLoc.insert(x);
}

void remove() {
    cin >> x;
    int loc = houseInfo[x];
    houseLoc.erase(loc);
}

int get_count(int t) {
    auto iter = houseLoc.begin();
    int loc = *iter;
    int sum = 0;
    int cnt = 1;

    iter++;

    for (; iter != houseLoc.end(); iter++) {
        int cur = *iter;
        int diff = cur - loc;

        if (sum + diff > t) {
            cnt++;
            sum = 0;
        }
        else {
            sum += diff;
        }
        loc = cur;
    }

    return cnt;
}

int search() {
    int r;
    cin >> r;

    int left = 0;
    int right = LIMIT;
    int ret = LIMIT;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = get_count(mid);

        // 불가한 경우
        if (cnt > r) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            ret = min(ret, mid);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Q;

    while (Q--) {
        cin >> CMD;

        switch (CMD) {
        case INIT:
            init();
            break;

        case ADD:
            add();
            break;

        case REMOVE:
            remove();
            break;

        case SEARCH:
            int ret = search();
            cout << ret << "\n";
            break;
        }
    }

    return 0;
}