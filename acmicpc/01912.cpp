#include <iostream>

using namespace std;

int arr[100001], dp[100001];

int main(){
	int n, answer = -2147000000;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)	scanf("%d", &arr[i]);
	
	for(int i = 1; i <= n ; i++){
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		answer = max(dp[i], answer);
	}
	
	printf("%d", answer);
}
