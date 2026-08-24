#include <iostream>
#include <string>

using namespace std;

string A;
int pre[100000];

int main() {
    cin >> A;

    for (int i = A.length() - 2; i >= 0; i--) {
        if (A[i] == ')' && A[i + 1] == ')') {
            pre[i] += 1;
        }
        pre[i] += pre[i + 1];
    }

    long long ret = 0;

    for (int i = 0; i < A.length() - 1; i++) {
        if (A[i] == '(' && A[i + 1] == '(') {
            ret += pre[i];
        }
    }

    cout << ret;

    return 0;
}
