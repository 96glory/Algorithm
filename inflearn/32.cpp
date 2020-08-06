#include <iostream>

using namespace std;

int arr[101];

int main(){
	int n, min = 987654321, minIndex = 0, temp;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	
	for(int i = 1; i < n; i++){
		for(int j = i; j <= n; j++){
			if(min >= arr[j]){
				min = arr[j];
				minIndex = j;
			}
		}
		
		temp = arr[i];
		arr[i] = min;
		arr[minIndex] = temp;
		
		min = 987654321;
	}
	
	for(int i = 1; i <= n; i++){
		printf("%d ", arr[i]);
	}
}

