#include <bits/stdc++.h>
#define MAX_COST 1000000000
using namespace std;

int a, b, c, n, m, arr[101][101], dp[101][101];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> a >> b >> c;
		arr[a][b] = dp[a][b] = c;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dp[i][j] == 0 && i != j)
				dp[i][j] = MAX_COST;
		}
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(k == i || k == j || i == j) continue;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dp[i][j] == MAX_COST) cout << "M ";
			else cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}
