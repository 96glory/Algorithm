#include <bits/stdc++.h>
using namespace std;

int n, m, arr[1001][1001], dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            // dp[i][j] = arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] += arr[i][j];
        }
    }

    cout << dp[n][m];
}