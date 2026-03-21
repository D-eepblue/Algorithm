#include <iostream>
#include<math.h>

using namespace std;

int n;
int a[10], b[10];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int num = 1;

    while (true) {
        bool isAnswer = true;
        for (int i = 0; i < n; i++) {
            int targetNum = num * pow(2, i + 1);
            if (targetNum < a[i] || targetNum > b[i]) {
                isAnswer = false;
                break;
            }
        }
        if (isAnswer) break;
        num++;
    }

    cout << num;

    return 0;
}