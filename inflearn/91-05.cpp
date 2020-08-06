#include <bits/stdc++.h>
using namespace std;

int n, arr[1001], dp[1001], answer;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	arr[0] = -1;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		int temp = 0;
		for(int j = 1; j < i; j++){
			if(arr[j] < arr[i] && dp[j] > temp)
				temp = dp[j];
		}
		dp[i] = temp + 1;
		answer = max(answer, dp[i]);
	}
	printf("%d", answer);
}

