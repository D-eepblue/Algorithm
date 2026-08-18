#include <iostream>
#include <queue>

using namespace std;

int N, sum;
int arr[100000];
int cnt[10001];
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        pq.push(-arr[i]);
        sum += arr[i];
        cnt[arr[i]]++;
    }

    double ret = 0;

    for (int k = 1; k <= N - 2; k++) {
        sum -= arr[k];
        cnt[arr[k]]--;

        while (!pq.empty()) {
            int top = -pq.top();

            // 이미 지워진 값은 빼버리기
            if (cnt[top] > 0) break;
            pq.pop();
        }

        double ans = (sum + pq.top());
        ans /= (N - k - 1);
        ret = max(ret, ans);
    }

    printf("%.2f\n", ret);

    return 0;
}