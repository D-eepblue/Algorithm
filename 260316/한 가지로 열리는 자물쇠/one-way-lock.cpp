#include <iostream>

using namespace std;

int N;
int a, b, c;

int main() {
    cin >> N;
    cin >> a >> b >> c;

    int ret = 0;

    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= N; j ++){
            for(int k = 1; k <= N; k ++){
                if(abs(a-i) <= 2 || abs(b-j) <= 2 || abs(c-k) <= 2) ret++;
            }
        }
    }

    cout << ret;

    return 0;
}