#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[66][66][66];

int f(int a, int b, int c){
	if(a <= 0 && b <= 0 && c <= 0) return 0;
	int &res = dp[a][b][c];
	if(res != -1) return res;
	int arr[3] = {1, 3, 9};

	int ans = 1e9+7;
	do{
		int x = a - arr[0]; x = max(x, 0);
		int y = b - arr[1]; y = max(y, 0);
		int z = c - arr[2]; z = max(z, 0);
		if(x > y) swap(x, y);
		if(x > z) swap(x, z);
		if(y > z) swap(y, z);
		ans = min(ans, f(x, y, z)+1);
	}while(next_permutation(arr, arr+3));
	return res = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n;
    cin >> n;

	memset(dp, -1, sizeof(dp));
	if(n == 1){
		int t; cin >> t;
		cout << f(0, 0, t);
	}
    else if(n == 2){
		int a, b; cin >> a >> b;
		if(a > b) swap(a, b);
		cout << f(0, a, b);
	}
    else{
		int a, b, c; cin >> a >> b >> c;
		if(a > b) swap(a, b);
		if(a > c) swap(a, c);
		if(b > c) swap(b, c);
		cout << f(a, b, c);
	}
}