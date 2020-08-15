#include <bits/stdc++.h>
using namespace std;

int cases, tar;
long long dp[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    dp[9] = 7;

    for(int i = 10; i <= 100; i++){
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    cin >> cases;
    while(cases--){
        cin >> tar;
        cout << dp[tar] << endl;
    }
}