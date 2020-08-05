#include <bits/stdc++.h>
using namespace std;

int n, a, b, d[16], p[16], dp[16];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		d[i] = a;
		p[i] = b;
	}
	
	for(int i = 1; i <= n; i++){
		int day = d[i] + i;
		int pay = p[i] + dp[i];
		
		for(int j = day; j <= n + 1; j++){
			dp[j] = max(dp[j], pay);
		}
	}
	
	cout << dp[n + 1];
}
