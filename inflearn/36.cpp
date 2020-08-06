#include <iostream>

using namespace std;

int arr[101];

int main(){
	int n, temp, i, j;
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	
	for(i = 2; i <= n; i++){
		temp = arr[i];
		for(j = i - 1; j >= 1; j--){
			if(arr[j] > temp)	arr[j + 1] = arr[j];
			else				break;
		}
		arr[j + 1] = temp;
	}
	
	for(i = 1; i <= n; i++)
		printf("%d ", arr[i]);
}

