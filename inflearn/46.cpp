#include <iostream>

using namespace std;

int main(){
	int n, k, time = 0, index = 1, endcnt = 0;
	scanf("%d", &n);
	int * arr = new int[n + 1];
	for(int i = 1; i <= n; i++)	scanf("%d", &arr[i]);
	scanf("%d", &k);
	
	while(endcnt != n && time < k){
		if(index > n)	index = 1;
		while(arr[index] <= 0){
			index++;
			if(index > n)	index = 1;	
		}
		if(arr[index] > 0){
			arr[index]--;
			if(arr[index] <= 0)	endcnt++;
			index++;
		}
		time++;
	}
	if(endcnt == n){
		printf("-1");
		return 0;
	}
	while(arr[index] <= 0){
		index++;
		if(index > n)	index = 1;	
	}
	printf("%d", index);
	delete[] arr;
}

