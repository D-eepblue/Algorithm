#include <iostream>
#include <set>
#include <tuple>

#define MAX_N 100000

using namespace std;
using ull = unsigned long long;

int N, T;
set<pair<int, int>> people_set;
set<tuple<ull, int, int>> event_set;
int pos[MAX_N], vel[MAX_N];

void add(int pos1, int vel1, int pos2, int vel2) {
    if (vel1 <= vel2) return;
    
    event_set.insert(make_tuple((pos2 - pos1) / (vel1 - vel2), pos1, vel1));
}

void remove(int pos1, int vel1, int pos2, int vel2) {
    if (vel1 <= vel2) return;

    event_set.erase(make_tuple((pos2 - pos1) / (vel1 - vel2), pos1, vel1));
}

int main() {
    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        cin >> pos[i] >> vel[i];
        people_set.insert({ pos[i], vel[i] });
    }

    for (int i = 0; i < N - 1; i++) {
        add(pos[i], vel[i], pos[i + 1], vel[i + 1]);
    }

    while (!event_set.empty()) {
        ull cur; 
        int pos, vel;
        tie(cur, pos, vel) = *event_set.begin();

        if (cur > T) break;

        people_set.erase(make_pair(pos, vel));
        event_set.erase(make_tuple(cur, pos, vel));

        auto iter = people_set.upper_bound(make_pair(pos, vel));
        int npos, nvel;
        tie(npos, nvel) = *iter;

        if (iter != people_set.begin()) {
            iter--;
            int ppos, pvel;
            tie(ppos, pvel) = *iter;
            remove(ppos, pvel, pos, vel);
            add(ppos, pvel, npos, nvel);
        }
    }

    cout << people_set.size();

    return 0;
}