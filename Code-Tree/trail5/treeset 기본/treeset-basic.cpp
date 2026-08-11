#include <iostream>
#include <set>
#include <string>

using namespace std;

int N, x;
set<int> mset;
string cmd;

int main() {
    cin >> N;

    while (N--) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            mset.insert(x);
        }
        if (cmd == "remove") {
            cin >> x;
            mset.erase(x);
        }
        if (cmd == "find") {
            cin >> x;
            if (mset.find(x) == mset.end()) cout << "false\n";
            else cout << "true\n";
        }
        if (cmd == "lower_bound") {
            cin >> x;
            auto iter = mset.lower_bound(x);
            if (iter == mset.end()) cout << "None\n";
            else cout << *iter << "\n";
        }
        if (cmd == "upper_bound") {
            cin >> x;
            auto iter = mset.upper_bound(x);
            if (iter == mset.end()) cout << "None\n";
            else cout << *iter << "\n";
        }
        if (cmd == "largest") {
            auto iter = mset.rbegin();
            if (iter == mset.rend()) cout << "None\n";
            else cout << *iter << "\n";
        }
        if (cmd == "smallest") {
            auto iter = mset.begin();
            if (iter == mset.end()) cout << "None\n";
            else cout << *iter << "\n";
        }
    }

    return 0;
}