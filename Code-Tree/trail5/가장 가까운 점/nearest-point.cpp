#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <functional>

using namespace std;

const int MAX_N = 100000;
int n, m, x, y;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pq.push(make_tuple(x + y, x, y));
    }

    for (int i = 0; i < m; i++) {
        int d, x, y;
        tie(d, x, y) = pq.top();
        pq.pop();
        pq.push(make_tuple(d + 4, x + 2, y + 2));
    }

    int d, x, y;
    tie(d, x, y) = pq.top();

    cout << x << " " << y;

    return 0;
}