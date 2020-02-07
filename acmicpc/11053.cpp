#include <iostream>

using namespace std;

int n, answer, arr[1001], dp[1001];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for(int i = 1; i <= n; i++){
		int min = 0;
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j]){
				if(min < dp[j])
					min = dp[j];
			}
		}
		dp[i] = min + 1;
		if(answer < dp[i])
			answer = dp[i];
	}
	
	cout << answer;
}
