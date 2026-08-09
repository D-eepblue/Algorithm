#include <iostream>
#include <unordered_set>

using namespace std;

const int MAX_N = 100000;
int n, v;
unordered_set<int> uset;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        uset.insert(v);
    }

    cout << uset.size();

    return 0;
}
