#include <bits/stdc++.h>
using namespace std;

int n, target;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	vector<int> coin;
	for(int i = 1; i <= n; i++){
		cin >> target;
		coin.push_back(target);
	}
	cin >> target;
	vector<int> dp(target + 1, 2147000000);
	
	dp[0] = 0;
	sort(coin.begin(), coin.end());
	for(auto c : coin){
		for(int i = c; i <= target; i += c){
			dp[i] = min(dp[i], i / c);
		}
		for(int i = c; i <= target; i++){
			dp[i] = min(dp[i], dp[i - c] + 1);
		}
	}
	
	cout << dp[target];
}
