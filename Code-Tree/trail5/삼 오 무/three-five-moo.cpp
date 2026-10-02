#include <iostream>

using namespace std;
using ll = long long;

constexpr ll MAX_N = 10'000'000'000;
ll n;

int main() {
    cin >> n;

    ll left = 1;
    ll right = MAX_N;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll val = mid - (mid / 3) - (mid / 5) + (mid / 15);

        if (val == n && mid % 3 != 0 && mid % 5 != 0) {
            cout << mid;
            break;
        }
        if (val >= n) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return 0;
}