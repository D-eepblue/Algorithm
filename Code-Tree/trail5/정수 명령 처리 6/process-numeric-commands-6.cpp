#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
string command;
priority_queue<int> pq;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "push") {
            int x;
            cin >> x;
            pq.push(x);
        }
        if (command == "pop") {
            cout << pq.top() << "\n";
            pq.pop();
        }
        if (command == "size") {
            cout << pq.size() << "\n";
        }
        if (command == "empty") {
            cout << (int)pq.empty() << "\n";
        }
        if (command == "top") {
            cout << pq.top() << "\n";
        }
    }

    return 0;
}