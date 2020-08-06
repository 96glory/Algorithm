#include <bits/stdc++.h>
using namespace std;

int n, m, ps, pt;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	vector<int> dp(m + 1, 0);
	
	for(int i = 0; i < n; i++){
		cin >> ps >> pt;
		for(int j = m; j >= pt; j--){
			dp[j] = max(dp[j], dp[j - pt] + ps);
		}
	}
	
	cout << dp[m];
}
