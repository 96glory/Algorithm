#include <bits/stdc++.h>
using namespace std;

int n, s, m, v;
bool dp[101][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> n >> s >> m;
    dp[0][s] = true;

    for (int i = 1; i <= n; i++) {
        cin >> v;
        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j]) {
                if (j + v <= m) dp[i][j + v] = true;
                if (j - v >= 0) dp[i][j - v] = true;
            }
        }
    }

    bool flag = false;
    for (int i = m; i >= 0; i--) {
        if (dp[n][i]) {
            cout << i;
            flag = true;
            break;
        }
    }
    if (!flag)   cout << -1;
}