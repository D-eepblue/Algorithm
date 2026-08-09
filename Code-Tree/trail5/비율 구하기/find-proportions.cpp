#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
map<string, int> m;
string word;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        m[word]++;
    }

    for (auto kv : m) {
        double val = (double)kv.second / n * 100;
        cout << kv.first << " ";
        printf("%.4f\n", val);
    }

    return 0;
}
