#define _CRT_SECURE_NO_WARNINGS
#include<queue>
#include<unordered_map>
#include<iostream>
#include<vector>

#define INIT   100
#define ADD    200
#define UPDATE 300
#define ATTACT 400

using namespace std;

struct BattleShip {
    int power;
    int reload;
    bool isReload;
};

struct ready {
    int power;
    int id;

    bool operator<(const ready& r) const {
        if (power == r.power) return id > r.id;
        return power < r.power;
    }
};

struct reload {
    int time;
    int id;

    bool operator<(const reload& r) const {
        return time > r.time;
    }
};

priority_queue<ready> ready_pq;
priority_queue<reload> reload_pq;
unordered_map<int, BattleShip> shipMap;
int T, N, CMD;
int cur_time;

void init() {
    int id, p, r;
    for (int i = 0; i < N; i++) {
        cin >> id >> p >> r;
        shipMap[id] = BattleShip{ p, r, false };
        ready_pq.push(ready{ p, id });
    }
}

void add() {
    int id, p, r;
    cin >> id >> p >> r;
    shipMap[id] = BattleShip{ p, r };
    ready_pq.push(ready{ p, id });
}

void update() {
    int id, p;
    cin >> id >> p;
    shipMap[id].power = p;
    
    // 재장전 중이 아니면 ready_pq에 다시 넣기
    if (!shipMap[id].isReload) {
        ready_pq.push(ready{ p, id });
    }
}

void attack() {
    int total_damage = 0;
    vector<int> attacklst;

    while (!ready_pq.empty() && attacklst.size() < 5) {
        ready top = ready_pq.top();
        ready_pq.pop();

        // 정보가 불일치 한 경우
        if (shipMap[top.id].power != top.power) continue;
        if (shipMap[top.id].isReload) {
            continue;
        }

        total_damage += top.power;
        attacklst.push_back(top.id);
    }

    cout << total_damage << " " << attacklst.size() << " ";

    for (int id : attacklst) {
        cout << id << " ";

        // reload_pq에 삽입
        int r = shipMap[id].reload;

        reload_pq.push(reload{ cur_time + r, id });
        shipMap[id].isReload = true;
    }

    cout << "\n";
}

void process(){
    while (!reload_pq.empty()) {
        reload top = reload_pq.top();

        if (top.time > cur_time) break;

        reload_pq.pop();
        ready_pq.push(ready{shipMap[top.id].power, top.id});
        shipMap[top.id].isReload = false;
    }
}

int main() {
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);

    cin >> T;

    for(cur_time = 1; cur_time <= T; cur_time ++){
        process();

        cin >> CMD;

        switch (CMD) {

        case INIT:
            cin >> N;
            init();
            break;

        case ADD:
            add();
            break;

        case UPDATE:
            update();
            break;

        case ATTACT:
            attack();
            break;
        }
    }

    return 0;
}