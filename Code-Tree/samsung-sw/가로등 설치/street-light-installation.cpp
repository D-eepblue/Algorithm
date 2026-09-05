#include <iostream>
#include <queue>
#include <set>
#include <math.h>
#include <algorithm>

#define INIT    100
#define    ADD        200
#define REMOVE    300
#define CALC    400

constexpr int MAX_LAMP = 200'005;

using namespace std;
using pii = pair<int, int>;

struct lamp {
    int dist, middle, id1, id2;

    bool operator<(const lamp& r) const {
        if (dist == r.dist) return middle > r.middle;
        return dist < r.dist;
    }
};

int Q, N, M, CMD, id;
int lampID = 0;
set<pii> lampOrder;
priority_queue<lamp> pq;
int lampLoc[MAX_LAMP];
bool removed[MAX_LAMP];

void init() {
    int loc;
    for (lampID = 1; lampID <= M; lampID++) {
        cin >> loc;

        // Lamp 정보 추가
        lampOrder.insert(pii{ loc, lampID });
        lampLoc[lampID] = loc;
        removed[lampID] = false;

        // begin 항목이 아닌 경우만 pq에 추가
        if (lampID != 1) {
            int dist = loc - lampLoc[lampID - 1];
            int middle = ceil((loc + lampLoc[lampID - 1]) / 2.0);
            pq.push(lamp{ dist, middle, lampID - 1, lampID });
        }
    }
}

void add() {
    while (!pq.empty()) {
        lamp top = pq.top();
        pq.pop();

        // 삭제된 경우
        if (removed[top.id1] || removed[top.id2]) continue;

        // 새로운 가로등 정보 추가
        int newID = lampID++;
        int newLoc = top.middle;
        
        lampOrder.insert(pii{ newLoc, newID });
        removed[newID] = false;
        lampLoc[newID] = newLoc;

        // pq에 정보 2개 추가
        // 첫번째
        int dist = newLoc - lampLoc[top.id1];
        int middle = ceil((newLoc + lampLoc[top.id1]) / 2.0);
        pq.push(lamp{ dist, middle, top.id1, newID });
        
        // 두번째
        dist = lampLoc[top.id2] - newLoc;
        middle = ceil((lampLoc[top.id2] + newLoc) / 2.0);
        pq.push(lamp{ dist, middle, newID, top.id2 });

        break;
    }
}

void remove(int mID) {
    removed[mID] = true;
    auto iter = lampOrder.find(pii{lampLoc[mID], mID});
    
    // 첫번째 또는 마지막 항목이 아닌 경우만
    if (iter != lampOrder.begin() && iter != prev(lampOrder.end())) {
        int pID = prev(iter)->second;
        int nID = next(iter)->second;
        int dist = lampLoc[nID] - lampLoc[pID];
        int middle = ceil((lampLoc[nID] + lampLoc[pID]) / 2.0);
        pq.push(lamp{ dist, middle, pID, nID });
    }

    lampOrder.erase(iter);
}

int calc() {
    int ret = 0;

    while (!pq.empty()) {
        lamp top = pq.top();

        // 삭제된 경우
        if (removed[top.id1] || removed[top.id2]) {
            pq.pop(); // 제거
            continue;
        }
        ret = top.dist;
        break;
    }

    int begin_dist = lampOrder.begin()->first - 1;
    int last_dist = N - prev(lampOrder.end())->first;

    ret = max(ret, begin_dist * 2);
    ret = max(ret, last_dist * 2);

    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> Q;

    while (Q--) {
        cin >> CMD;

        switch (CMD)
        {
        case INIT :
            cin >> N >> M;
            init();
            break;
        case ADD:
            add();
            break;
        case REMOVE:
            cin >> id;
            remove(id);
            break;
        case CALC:
            int ret = calc();
            cout << ret << "\n";
            break;
        }
    }

    return 0;
}