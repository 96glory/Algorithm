#include <bits/stdc++.h>
using namespace std;

int cases, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> cases;
    while (cases--) {
        cin >> n;
        int arr[n + 1] ={ 0, };
        int sum[n + 1] ={ 0, };
        int dp[n + 1][n + 1] ={ 0, };

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }

        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j > 0; j--) {
                dp[j][i] = 2147000000;
                for (int k = j; k <= i; k++) {
                    dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i]);
                }
                dp[j][i] += sum[i] - sum[j - 1];
            }
        }

        cout << dp[1][n] << '\n';
    }
}