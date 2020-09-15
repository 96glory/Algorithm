#include <bits/stdc++.h>
using namespace std;

int n, arr[1001], dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        dp[i] = 2147000000;
    }

    dp[1] = 0;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= min(arr[i] + i, n); j++){
            dp[j] = min(dp[i] + 1, dp[j]);
        }
    }

    if(dp[n] == 2147000000) cout << -1;
    else cout << dp[n];
}