#include <iostream>
#include <math.h>

using namespace std;

int X, Y;

int main() {
    cin >> X >> Y;

    int cnt = 0;

    X = max(X, 11);
    Y = min(Y, 999999);

    for (int number = X; number <= Y; number++) {
        int arr[6] = { -1, };
        for (int i = 0; i < 6; i++) {
            arr[i] = (number / (int)pow(10, 5-i)) % 10;
        }

        if (number >= 100'000) {
            if (arr[0] == arr[5] && arr[1] == arr[4] && arr[2] == arr[3]) cnt++;
        }
        else if (number >= 10'000) {
            if (arr[1] == arr[5] && arr[2] == arr[4]) cnt++;
        }
        else if (number >= 1'000) {
            if (arr[2] == arr[5] && arr[3] == arr[4]) cnt++;
        }
        else if (number >= 100) {
            if (arr[3] == arr[5]) cnt++;
        }
        else {
            if (arr[4] == arr[5]) cnt++;
        }
    }

    cout << cnt;

    return 0;
}