#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, k, v;
string cmd;
map<int, int> m;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> k >> v;
            m[k] = v;
        }
        else if (cmd == "remove") {
            cin >> k;
            m.erase(k);
        }
        else if(cmd == "find"){
            cin >> k;
            if (m.find(k) == m.end()) {
                cout << "None" << "\n";
            }
            else {
                cout << m[k] << "\n";
            }
        }
        else {
            if (m.size() > 0) {
                for (auto kv : m) {
                    cout << kv.second << " ";
                }
            }
            else {
                cout << "None";
            }
            cout << "\n";
        }
    }

    // Please write your code here.

    return 0;
}
