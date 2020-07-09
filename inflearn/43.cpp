#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001], n;

int count(int size){
	int i, cnt = 1, sum = 0;
	for(i = 1; i <= n; i++){
		if(sum + arr[i] > size){
			cnt++;
			sum = arr[i];
		}
		else	sum += arr[i];
	}
	
	return cnt;
}

int main(){
	int m, i, left = 1, right = 0, mid, answer, max = -987654321;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
		right += arr[i];
		if(arr[i] > max)	max = arr[i];
	}
	
	while(left <= right){
		mid = (left + right) / 2;
		if(mid >= max && count(mid) <= m){
			answer = mid;
			right = mid - 1;
		}
		else	left = mid + 1;
	}
	
	printf("%d", answer);
}

