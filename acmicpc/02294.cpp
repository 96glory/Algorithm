#include <bits/stdc++.h>
#define _MAX 2147000000
using namespace std;

int n, k, coin, dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        dp[i] = _MAX;
    }

    for (int i = 1; i <= n; i++) {
        cin >> coin;
        for (int j = coin; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    if (dp[k] == _MAX)  cout << -1;
    else                cout << dp[k];
}