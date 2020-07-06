#include <iostream>

using namespace std;

int arr[101];

int main(){
	int n, max = -1, answer = 101;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= n; j++){
			if(answer > arr[j] && max <= arr[j])	max = arr[j];
		}
		answer = max;
		max = -1;
	}

	printf("%d", answer);
}
