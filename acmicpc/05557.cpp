#include <bits/stdc++.h>
using namespace std;

int n, num;
long long dp[101][21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> num;
    dp[1][num] = 1;

    for (int i = 2; i <= n - 1; i++) {
        cin >> num;
        for (int j = 0; j <= 20; j++) {
            if (dp[i - 1][j] > 0) {
                if (j + num <= 20)    dp[i][j + num] += dp[i - 1][j];
                if (j - num >= 0)     dp[i][j - num] += dp[i - 1][j];
            }
        }
    }

    cin >> num;
    cout << dp[n - 1][num];
}