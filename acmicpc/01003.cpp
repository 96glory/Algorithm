#include <bits/stdc++.h>
using namespace std;

int cases, tar;
long long dp[41][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    dp[0][0] = 1; dp[0][1] = 0;
    dp[1][0] = 0; dp[1][1] = 1;

    for (int i = 2; i <= 40; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }

    cin >> cases;
    while (cases--) {
        cin >> tar;
        cout << dp[tar][0] << " " << dp[tar][1] << '\n';
    }
}