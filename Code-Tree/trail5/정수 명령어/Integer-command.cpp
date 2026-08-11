#include <iostream>
#include <set>

using namespace std;

int T, K, x;
char cmd;
set<int> mset;

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> K;
        mset.clear();

        for (int i = 0; i < K; i++) {
            cin >> cmd >> x;

            if (cmd == 'I') {
                mset.insert(x);
            }
            else if (cmd == 'D' && x == 1) {
                if (mset.size() > 0) {
                    mset.erase(*mset.rbegin());
                }
            }
            else {
                if (mset.size() > 0) {
                    mset.erase(*mset.begin());
                }
            }
        }

        if (mset.size() > 0) {
            cout << *mset.rbegin() << " " << *mset.begin() << "\n";
        }
        else {
            cout << "EMPTY\n";
        }
    }

    return 0;
}
