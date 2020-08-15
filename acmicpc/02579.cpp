#include <bits/stdc++.h>
using namespace std;

int n, stair[301], dp[301];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> stair[i];
    }

    dp[1] = stair[1];
    dp[2] = max(stair[2], stair[1] + stair[2]);
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

    for(int i = 3; i <= n; i++){
        dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);
    }
    
    cout << dp[n];
}