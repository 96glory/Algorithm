#include <bits/stdc++.h>
#define PUDDLE -1
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    for(auto k : puddles)   dp[k[1]][k[0]] = PUDDLE;
    for(int i = 1; i <= m; i++){
        if(dp[1][i] == PUDDLE)  break;
        dp[1][i] = 1;
    }
    for(int i = 1; i <= n; i ++){
        if(dp[i][1] == PUDDLE)  break;
        dp[i][1] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            if(dp[i][j] == PUDDLE)  continue;
            if(dp[i - 1][j] != PUDDLE)  dp[i][j] += dp[i - 1][j];
            if(dp[i][j - 1] != PUDDLE)  dp[i][j] += dp[i][j - 1];
            dp[i][j] %= 1000000007;
        }
    }

    return dp[n][m];
}
