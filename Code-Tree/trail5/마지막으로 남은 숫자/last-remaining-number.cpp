#include <iostream>
#include <queue>

using namespace std;

int n, x;
priority_queue<int> pq;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    while (pq.size() >= 2) {
        int num1 = pq.top(); pq.pop();
        int num2 = pq.top(); pq.pop();
        int diff = abs(num1 - num2);

        if (diff == 0) continue;
        
        pq.push(diff);
    }

    if (pq.size() == 0) cout << -1;
    else cout << pq.top();

    return 0;
}