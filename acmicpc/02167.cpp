#include <bits/stdc++.h>
using namespace std;

int arr[301][301], dp[301][301], n, m, cases, x, y, xx, yy;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    cin >> cases;
    while (cases--) {
        cin >> x >> y >> xx >> yy;
        cout << dp[xx][yy] - dp[x - 1][yy] - dp[xx][y - 1] + dp[x - 1][y - 1] << endl;
    }
}