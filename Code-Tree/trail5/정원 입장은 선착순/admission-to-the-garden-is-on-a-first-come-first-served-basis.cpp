#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 100005

using namespace std;
using pii = pair<int, int>;

int N, a[MAX_N], t[MAX_N];
priority_queue<pii, vector<pii>, greater<>> pq;
priority_queue<int, vector<int>, greater<>> pq2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> t[i];
        pq.push(pii{a[i], i});
    }
    
    pii top = pq.top();
    pq.pop();

    int ret = 0;
    int cur_time = top.first + t[top.second];

    while (!pq.empty()) {

        while (!pq.empty()) {
            if (pq.top().first > cur_time) break;
            pii t = pq.top();
            pq.pop();
            pq2.push(t.second);
        }

        if (pq2.empty()) {
            pii t = pq.top();
            pq.pop();
            pq2.push(t.second);
            cur_time = a[t.second];
        }

        int idx = pq2.top();
        pq2.pop();

        ret = max(ret, cur_time - a[idx]);
        cur_time += t[idx];
    }
    
    std::cout << ret;

    return 0;
}