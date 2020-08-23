#include <bits/stdc++.h>
using namespace std;

int cases, n, arr[101][101], dp[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> cases;
    while(cases--){
        cin >> n;

        dp[1][1] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> arr[i][j];
                if(dp[i][j] == 1){
                    if(i + arr[i][j] <= n)  dp[i + arr[i][j]][j] = 1;
                    if(j + arr[i][j] <= n)  dp[i][j + arr[i][j]] = 1;
                }
            }
        }

        if(dp[n][n] == 1)   cout << "YES" << endl;
        else                cout << "NO" << endl;
        
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
    }
}