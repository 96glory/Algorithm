#include <bits/stdc++.h>
using namespace std;

int n, k, coin[101], dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= coin[i]) {
                dp[j] += dp[j - coin[i]];
            }
        }
    }

    cout << dp[k];
}