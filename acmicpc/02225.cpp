#include <bits/stdc++.h>
#define DIV 1000000000
using namespace std;

// dp[i][j] : i개의 수로 j를 만들 수 있는 경우의 수를 저장
int n, k, dp[201][201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> k;
    
    for (int i = 0; i <= n; i++)    dp[1][i] = 1;
    for (int i = 0; i <= k; i++)    dp[i][0] = 1;

    for(int i = 2; i <= k; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % DIV;
        }
    }

    cout << dp[k][n];
}