#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

#define MAX_NUM 100000

using namespace std;

int n, m, k;

int arr1[MAX_NUM];
int arr2[MAX_NUM];
priority_queue<tuple<int, int, int> > pq;

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    // 처음에는 n개의 원소에 대해 각각 
    // 두 번째 수열의 첫 번째 원소를 대응시켜줍니다.
    // 작은 값이 더 먼저 나와야 하므로
    // -를 붙여서 넣어줍니다. 
    for (int i = 0; i < n; i++)
        pq.push(make_tuple(-(arr1[i] + arr2[0]), i, 0));

    // 1번부터 k - 1번까지 합이 작은 쌍을 골라줍니다.
    for (int i = 0; i < k - 1; i++) {
        int idx1, idx2;
        tie(ignore, idx1, idx2) = pq.top();
        pq.pop();

        // 만약 첫 번째 수열의 idx1번째 원소와 더 매칭할 두 번째 수열의 원소가 남아있다면
        // 우선순위 큐에 넣어줍니다.
        idx2++;
        if (idx2 < m)
            pq.push(make_tuple(-(arr1[idx1] + arr2[idx2]), idx1, idx2));
    }

    // k번째 합을 가져옵니다.
    int pair_sum;
    tie(pair_sum, ignore, ignore) = pq.top();

    cout << -pair_sum;
    return 0;
}