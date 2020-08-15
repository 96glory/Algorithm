#include <bits/stdc++.h>
using namespace std;

int cases, n, m;
long long dp[30][30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    for(int i = 0; i <= 29; i++ ){
        for(int j = 0; j <= 29; j++){
            if(i == j || j == 0)    dp[i][j] = 1;
            else                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cin >> cases;
    while(cases--){
        cin >> n >> m;
        cout << dp[m][n] << endl;
    }
}