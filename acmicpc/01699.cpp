#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1, dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i == cnt * cnt) {
            dp[i] = 1;
            cnt++;
        }
        else {
            dp[i] = 2147000000;
            for (int j = 1; j <= cnt - 1; j++) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
    }

    cout << dp[n];
}