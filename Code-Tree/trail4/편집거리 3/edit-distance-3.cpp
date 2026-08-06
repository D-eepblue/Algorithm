#include <iostream>
#include <string>

#define MAX_LEN 1001

using namespace std;

string A, B;
int dp[MAX_LEN][MAX_LEN];

int main() {
    cin >> A;
    cin >> B;

    A = "#" + A;
    B = "#" + B;
    // inital
    dp[0][0] = 0;

    for (int i = 1; i <= A.length(); i++) {
        dp[0][i] = dp[0][i - 1] + 1;
    }

    for (int i = 1; i <= B.length(); i++) {
        dp[i][0] = dp[i - 1][0] + 1;
    }

    // dp-table setting
    for (int i = 1; i <= B.length(); i++) {
        for (int j = 1; j <= A.length(); j++) {
            if (A[j] == B[i]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    
    cout << dp[B.length()][A.length()];

    return 0;
}