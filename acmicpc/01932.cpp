#include <bits/stdc++.h>
using namespace std;

int n, tri[501][501], dp[501][501], answer = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> tri[i][j];
        }
    }

    dp[1][1] = tri[1][1];

    for(int j = 2; j <= n; j++){
        dp[j][1] = dp[j - 1][1] + tri[j][1];
        dp[j][j] = dp[j - 1][j - 1] + tri[j][j];
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= i - 1; j++){
            dp[i][j] = tri[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    for(int i = 1; i <= n; i++){
        answer = max(answer, dp[n][i]);
    }
    cout << answer;
}