#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i <= 5)
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = max({ dp[i - 1] + 1, dp[i - 3] * 2, dp[i - 4] * 3, dp[i - 5] * 4 });
    }

    cout << dp[n];
}