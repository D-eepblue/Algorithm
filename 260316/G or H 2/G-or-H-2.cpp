#include <iostream>
#include <algorithm>

using namespace std;

int N, p;
char alpha;
int line[101];
int pos[101];

bool check(int left, int right) {
    int H = 0, G = 0;

    for (int i = left; i < right; i++) {
        int val = line[pos[i]];
        if (val == 1) H++;
        else if (val == 2) G++;
    }

    return H == G || H == 0 || G == 0;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> p >> alpha;
        line[p] = alpha == 'H' ? 1 : 2;
        pos[i] = p;
    }

    sort(pos, pos + N);

    int dist = 0;

    for (int size = N; size > 0; size--) {
        for (int start = 0; start <= N - size; start++) {
            if (check(start, start + size)) {
                dist = max(dist, pos[start + size - 1] - pos[start]);
            }
        }
    }

    cout << dist;

    return 0;
}