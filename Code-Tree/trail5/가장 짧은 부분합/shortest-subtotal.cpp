#include <iostream>

using namespace std;

constexpr int MAX_N = 100'001;

int N, S;
int arr[MAX_N];
int ret = MAX_N;

int main() {
    cin >> N >> S;

    for (int i = 0; i < N; i++) cin >> arr[i];

    int sum_val = 0;
    int cnt = 0;
    int j = 0;

    for (int i = 0; i < N; i++) {

        while (sum_val < S && j < N) {
            sum_val += arr[j];
            cnt++;
            j++;
        }

        if(sum_val >= S)
            ret = min(ret, cnt);

        sum_val -= arr[i];
        cnt--;
    }

    if (ret == MAX_N) ret = -1;

    cout << ret;

    return 0;
}