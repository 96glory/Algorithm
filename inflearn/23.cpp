#include <iostream>

using namespace std;

int arr[100001];

int main(){
	int n, pre = 0, cnt = 0, answer = 1;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i = 1; i <= n; i++){
		if(pre <= arr[i]){
			pre = arr[i];
			cnt++;
		}
		else{
			if(cnt > answer){
				answer = cnt;
			}
			cnt = 1;
			pre = arr[i];
		}
	}
	if(cnt > answer){
		answer = cnt;
	}
	
	printf("%d", answer);
}

