#include <bits/stdc++.h>
#define INF 2147000000
#define R 0
#define G 1
#define B 2
using namespace std;

int n, cost[1001][3], dp[1001][3], answer = INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> cost[i][R] >> cost[i][G] >> cost[i][B];

    for(int rgb = 0; rgb < 3; rgb++){
        memset(dp, 0, sizeof(dp));

        dp[1][R] = dp[1][G] = dp[1][B] = INF;
        dp[1][rgb] = cost[1][rgb];
        for (int i = 2; i <= n; i++) {
            dp[i][R] = min(dp[i - 1][G] + cost[i][R], dp[i - 1][B] + cost[i][R]);
            dp[i][G] = min(dp[i - 1][R] + cost[i][G], dp[i - 1][B] + cost[i][G]);
            dp[i][B] = min(dp[i - 1][R] + cost[i][B], dp[i - 1][G] + cost[i][B]);
        }

        for(int i = 0; i < 3; i++){
            if(i == rgb) continue;
            answer = min(answer, dp[n][i]);
        }
    }

    cout << answer;
}