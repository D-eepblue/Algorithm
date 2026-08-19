#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int MAX_N = 100000;
int n, v;
priority_queue<pii, vector<pii>, greater<>> pq;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v;
        if (v == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                pii top = pq.top();
                pq.pop();

                cout << top.second << "\n";
            }
        }
        else {
            pq.push(pii{ abs(v), v });
        }
    }

    return 0;
}