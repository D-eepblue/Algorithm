#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int n, x;
string cmd;
unordered_set<int> uset;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd >> x;
        if (cmd == "find") {
            if (uset.find(x) == uset.end()) {
                cout << "false\n";
            }
            else cout << "true\n";
        }
        else if (cmd == "add") {
            uset.insert(x);
        }
        else if (cmd == "remove") {
            uset.erase(x);
        }
    }

    return 0;
}
