#include <iostream>

using namespace std;

int N, K, B, miss;
int arr[100001];
int prefix[100001];

int main() {
    cin >> N >> K >> B;
    
    for (int i = 1; i <= N; i++) arr[i] = 1;
    for (int i = 0; i < B; i++) {
        cin >> miss;
        arr[miss] = 0;
    }

    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int ret = B;

    for (int i = K; i <= N; i++) {
        int miss_cnt = K - (prefix[i] - prefix[i - K]);
        ret = min(ret, miss_cnt);
    }

    cout << ret;

    return 0;
}
