#include <bits/stdc++.h>
using namespace std;

string a, b;
int alen, blen, dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> a >> b;
    alen = a.length();
    blen = b.length();

    for (int i = 1; i <= alen; i++) {
        for (int j = 1; j <= blen; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[alen][blen];
}