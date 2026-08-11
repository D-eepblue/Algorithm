#include <iostream>
#include <unordered_set>
#include <queue>

#define MAX_N 100005
#define MAX_G 250005

using namespace std;

int N, G;
int val, gcnt;
bool invited[MAX_N];
unordered_set<int> group[MAX_G];
queue<int> q;

int main() {
    cin >> N >> G;

    for (int i = 0; i < G; i++) {
        cin >> gcnt;

        for (int j = 0; j < gcnt; j++) {
            cin >> val;
            group[i].insert(val);
        }
    }

    q.push(1);

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        if (invited[i]) continue;
        invited[i] = true;

        for (int j = 0; j < G; j++) {
            if (group[j].count(i) > 0) {
                group[j].erase(i);
            }
            if (group[j].size() == 1) {
                int idx = *group[j].begin();
                group[j].erase(idx);
                
                if(!invited[idx])
                    q.push(idx);
            }
        }
    }

    int ret = 0;

    for (int i = 1; i <= N; i++) {
        if (invited[i]) ret++;
    }

    cout << ret;

    return 0;
}