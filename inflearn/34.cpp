#include <iostream>

using namespace std;

int arr[101];

int main(){
	int n, temp;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for(int i = 1; i < n; i++){
		for(int j = 1; j < n - i; j++){
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j] = temp;
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
		printf("%d ", arr[i]);
}

