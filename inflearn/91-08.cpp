#include <bits/stdc++.h>
using namespace std;

int n, m, w, v;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	vector<int> dp(m + 1, 0);
	
	for(int i = 0; i < n; i++){
		cin >> w >> v;
		for(int j = w; j < m; j++){
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	
	cout << dp[m];
}
