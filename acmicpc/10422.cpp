#include <bits/stdc++.h>
using namespace std;

int cases, tar;
long long dp[5001];

long long d(int L) {
    if (L == 0)             return 1;
    else if (dp[L] >= 0)    return dp[L];
    dp[L] = 0;
    for (int i = 2; i <= L; i += 2) {
        dp[L] += (d(i - 2) * d(L - i));
        dp[L] %= 1000000007;
    }
    return dp[L];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> cases;
    while (cases--) {
        cin >> tar;
        if (tar % 2 == 1)
            cout << 0 << endl;
        else
            cout << d(tar) << endl;
    }
}