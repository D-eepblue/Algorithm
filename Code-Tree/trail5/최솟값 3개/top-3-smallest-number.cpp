#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ull = unsigned long long;

int n, v;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        pq.push(v);
        if (pq.size() < 3) {
            cout << -1 << "\n";
        }
        else {
            int num1 = pq.top(); pq.pop();
            int num2 = pq.top(); pq.pop();
            ull v = (ull)num1 * (ull)num2;
            v *= (ull)pq.top();
            cout << v << "\n";
            pq.push(num1);
            pq.push(num2);
        }
    }

    return 0;
}
