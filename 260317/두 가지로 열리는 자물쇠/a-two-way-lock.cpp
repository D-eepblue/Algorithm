#include <iostream>

using namespace std;

int N;
int a1, b1, c1;
int a2, b2, c2;

int main() {
    cin >> N;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    int ret = 0;

    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= N; j ++){
            for(int k = 1; k <= N; k ++){
                int modN = N - 2;
                if(abs(i - a1) % modN <= 2 && abs(j - b1) % modN <= 2 && abs(k - c1) % modN <= 2) ret++;
                else if(abs(i - a2) % modN <= 2 && abs(j - b2) % modN <= 2 && abs(k - c2) % modN <= 2) ret++;
            }
        }
    }

    cout << ret;

    return 0;
}