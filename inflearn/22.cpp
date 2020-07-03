#include <iostream>

using namespace std;

int arr[100001];

int main(){
	int n, k, max = -987654321;
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	
	int sum = 0;
	for(int i = 1; i <= n - k + 1; i++){
		if(i == 1){
			for(int j = 1; j <= k; j++){
				sum += arr[j];
			}
		}
		else{
			sum = sum - arr[i - 1] + arr[i + k - 1];
		}
		
		if(sum > max){
			max = sum;
		}
	}
	
	printf("%d", max);
}

