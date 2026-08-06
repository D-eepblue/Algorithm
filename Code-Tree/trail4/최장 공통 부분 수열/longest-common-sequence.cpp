#include <iostream>
#include <string>

#define MAX_LEN 1001

using namespace std;

string A, B;
int dp[MAX_LEN][MAX_LEN];

int main() {
    cin >> A;
    cin >> B;

    // inital
    dp[0][0] = (A[0] == B[0]) ? 1 : 0;

    for (int i = 1; i < A.length(); i++) {
        if (B[0] == A[i]) {
            dp[0][i] = 1;
        }
        else {
            dp[0][i] = dp[0][i - 1];
        }
    }

    for (int i = 1; i < B.length(); i++) {
        if (B[i] == A[0]) {
            dp[i][0] = 1;
        }
        else {
            dp[i][0] = dp[i - 1][0];
        }
    }

    // dp-table setting
    for (int i = 1; i < B.length(); i++) {
        for (int j = 1; j < A.length(); j++) {
            if (A[j] == B[i]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[B.length() - 1][A.length() - 1];

    return 0;
}