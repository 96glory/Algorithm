#include <bits/stdc++.h>
using namespace std;

int a, b, n, dp[51][51], result[51];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	while(-1){
		cin >> a >> b;
		if(a == -1 & b == -1) break;
		dp[a][b] = 1;
		dp[b][a] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	int min_cost = 6;
	vector<int> res;
	for(int i = 1; i <= n; i++){
		int temp = -1;
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			temp = max(temp, dp[i][j]);
		}
		min_cost = min(min_cost, temp);
		result[i] = temp;
	}
	
	for(int i = 1; i <= n; i++){
		if(min_cost == result[i])
			res.push_back(i);
	}
	
	cout << min_cost << " " << res.size() << endl;
	for(auto k : res){
		cout << k << " ";
	}
	
	
}
