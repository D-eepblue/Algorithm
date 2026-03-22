#include <iostream>
#include <algorithm>

using namespace std;

int nums[15];

bool compare_array(int a, int b, int c, int d) {
    int comp[15] = { 0, };
    int idx = 0;
    comp[idx++] = a, comp[idx++] = b, comp[idx++] = c, comp[idx++] = d;
    comp[idx++] = a + b;
    comp[idx++] = b + c;
    comp[idx++] = c + d;
    comp[idx++] = d + a;
    comp[idx++] = a + c;
    comp[idx++] = b + d;
    comp[idx++] = a + b + c;
    comp[idx++] = a + b + d;
    comp[idx++] = a + c + d;
    comp[idx++] = b + c + d;
    comp[idx++] = a + b + c + d;
    sort(comp, comp + 15);

    bool isEqual = true;

    for (int i = 0; i < 15; i++) {
        if (nums[i] != comp[i]) {
            isEqual = false;
            break;
        }
    }
    
    return isEqual;
}


int main() {
    for (int i = 0; i < 15; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + 15);

    for (int a = 1; a <= 10; a++) {
        for (int b = a; b <= 10; b++) {
            for (int c = b; c <= 10; c++) {
                for (int d = c; d <= 10; d++) {
                    if (compare_array(a, b, c, d)) {
                        cout << a << " " << b << " " << c << " " << d;
                        return 0;
                    }
                }
            }

        }
    }

    return 0;
}