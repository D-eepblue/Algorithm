#include <iostream>
#include <string>
#include <set>

using namespace std;
using pii = pair<int, int>;

int n, m;
int P, L;
set<pii> mset;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> P >> L;
        mset.insert({ L, P });
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string command;
        cin >> command;

        if (command == "rc") {
            int x;
            cin >> x;

            if (x == 1) {
                int num = mset.rbegin()->second;
                cout << num << "\n";
            }
            else {
                int num = mset.begin()->second;
                cout << num << "\n";
            }
        }
        else if (command == "ad") {
            int p, l;
            cin >> p >> l;
            mset.insert({ l, p });
        }
        else if (command == "sv") {
            int p, l;
            cin >> p >> l;
            mset.erase({ l, p });
        }
    }

    return 0;
}