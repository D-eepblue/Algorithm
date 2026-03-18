#include <iostream>

using namespace std;

int N;
int x[100];
int y[100];
int surf = 0;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int h = 0, w = 0;
                if (x[i] == x[j] && y[i] == y[k]) {
                    w = abs(x[i] - x[k]);
                    h = abs(y[i] - y[j]);
                }
                else if (x[j] == x[k] && y[j] == y[i]) {
                    w = abs(x[j] - x[i]);
                    h = abs(y[j] - y[k]);
                }
                else if (x[k] == x[i] && y[k] == y[j]) {
                    w = abs(x[k] - x[j]);
                    h = abs(y[k] - y[i]);
                }

                surf = max(surf, h * w);
            }
        }
    }

    cout << surf;

    return 0;
}