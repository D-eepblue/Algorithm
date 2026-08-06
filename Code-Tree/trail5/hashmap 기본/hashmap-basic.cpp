#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int N;
string cmd;
int a, b;
unordered_map<int, int> umap;

int main() {
    cin >> N;

    while (N--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> a >> b;
            umap[a] = b;
            continue;
        }

        cin >> a;

        if (cmd == "find") {
            if (umap.count(a)) {
                cout << umap[a] << "\n";
            }
            else {
                cout << "None\n";
            }
        }
        else {
            umap.erase(a);
        }
    }
    return 0;
}