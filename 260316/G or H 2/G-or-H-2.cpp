#include <iostream>
#include <algorithm>

using namespace std;

int N, p;
char alpha;
int line[101];
int pos[101];

bool check(int left, int right) {
    int H = 0, G = 0;

    for (int i = left; i <= right; i++) {
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

    int left = 0, right = N - 1;
    int dist = 0;

    while (left <= right) {
        if (check(left, right)) {
            dist = max(dist, pos[right] - pos[left]);
            break;
        }
        if (check(left + 1, right))
            dist = max(dist, pos[right] - pos[left + 1]);

        if (check(left, right - 1))
            dist = max(dist, pos[right-1] - pos[left]);

        left++, right--;
    }

    cout << dist;

    return 0;
}