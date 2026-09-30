#include <iostream>
#include <math.h>

using namespace std;
using ll = unsigned long long;

ll s;

int main() {
    cin >> s;

    ll max_num = 0;
    ll left = 1;
    ll right = sqrt(s * 2) + 1;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll val = mid * (mid + 1) / 2;

        if (val <= s) {
            left = mid + 1;
            max_num = max(max_num, mid);
        }
        else {
            right = mid - 1;
        }
    }
    
    cout << max_num;

    return 0;
}
