#include <bits/stdc++.h>
using namespace std;

int n, arr[22][22], trace[22][22];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> arr[i][j];
	
	for(int i = 1; i <= n; i++){
		trace[1][i] = trace[1][i - 1] + arr[1][i];
		trace[i][1] = trace[i - 1][1] + arr[i][1];
	}
	
	for(int i = 2; i <= n; i++)
		for(int j = 2; j <= n; j++)
			trace[i][j] = min(trace[i][j - 1] + arr[i][j], trace[i - 1][j] + arr[i][j]);
		
	cout << trace[n][n];
}

