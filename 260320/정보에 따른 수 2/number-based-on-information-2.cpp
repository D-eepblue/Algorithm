#include <iostream>

using namespace std;

int T, a, b;
int x;
char c;
char line[1001];

int main() {
    cin >> T >> a >> b;

    for (int i = 0; i < T; i++) {
        cin >> c >> x;
        line[x] = c;
    }
    
    int ret = 0;

    for (int pos = a; pos <= b; pos++) {
        int dS = 1001;
        int dN = 1001;
        // left search
        for (int left = pos; left >= 0; left--) {
            if (line[left] == 'N') dN = min(dN, pos - left);
            else if (line[left] == 'S') dS = min(dS, pos - left);
        }

        // right serch
        for (int right = pos; right <= 1000; right++) {
            if (line[right] == 'N') dN = min(dN, right - pos);
            else if (line[right] == 'S') dS = min(dS, right - pos);
        }
        if (dS <= dN) ret++;
    }

    cout << ret;

    return 0;
}