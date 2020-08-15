#include <bits/stdc++.h>
using namespace std;

int n, arr[1001][3], dp[1001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1] + arr[i][0], dp[i - 1][2] + arr[i][0]);
        dp[i][1] = min(dp[i - 1][0] + arr[i][1], dp[i - 1][2] + arr[i][1]);
        dp[i][2] = min(dp[i - 1][0] + arr[i][2], dp[i - 1][1] + arr[i][2]);
    }

    cout << min({ dp[n][0], dp[n][1], dp[n][2] });
}