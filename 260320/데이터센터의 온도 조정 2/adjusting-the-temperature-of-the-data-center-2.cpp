#include <iostream>

using namespace std;

int N, C, G, H;
int Ta[1000], Tb[1000];

int main() {
    cin >> N >> C >> G >> H;

    for (int i = 0; i < N; i++) {
        cin >> Ta[i] >> Tb[i];
    }

    int ret = 0;

    for (int temp = 0; temp <= 1000; temp++) {
        int tp = 0;
        for (int i = 0; i < N; i++) {
            if (Ta[i] > temp) tp += C;
            else if (Ta[i] <= temp && Tb[i] >= temp) tp += G;
            else tp += H;
        }
        ret = max(ret, tp);
    }

    cout << ret;

    return 0;
}