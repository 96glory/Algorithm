#include <bits/stdc++.h>
#define MOD 9901
#define E 0
#define L 1
#define R 2
using namespace std;

int n, dp[100001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    
    dp[1][E] = dp[1][L] = dp[1][R] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i][E] = (dp[i - 1][E] + dp[i - 1][L] + dp[i - 1][R]) % MOD;
        dp[i][L] = (dp[i - 1][E] + dp[i - 1][R]) % MOD;
        dp[i][R] = (dp[i - 1][E] + dp[i - 1][L]) % MOD;
    }

    cout << (dp[n][E] + dp[n][L] + dp[n][R]) % MOD;
}