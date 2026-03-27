#include <iostream>
#include <algorithm>

using namespace std;

constexpr int limit = 17;

int N;
int heights[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    int ret = 0;
    
    while (true) {
        sort(heights, heights + N);

        int diff = abs(heights[0] - heights[N - 1]);
        
        if (diff <= limit) break;

        int val1 = (diff - limit) / 2;
        int val2 = val1 + ((diff - limit) % 2 ? 1 : 0);
        
        heights[0] += val1;
        heights[N - 1] -= val2;
        ret += val1 * val1;
        ret += val2 * val2;
    }

    cout << ret;

    return 0;
}