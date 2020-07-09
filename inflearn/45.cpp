#include <iostream>

using namespace std;

int arr[1000] = {0, };

int main(){
	int n, k, index = 0;
	scanf("%d", &n);	scanf("%d", &k);
	
	for(int i = 0; i < n - 1; i++){
		for(int j = 1; j < k; ){
			if(arr[index] == 0)	j++;
			index = (index + 1) % n;
		}
		while(arr[index] != 0)	index = (index + 1) % n;
		arr[index] = -1;
		while(arr[index] != 0)	index = (index + 1) % n;
	}
	
	for(int i = 0; i < n; i++){
		if(arr[i] == 0){
			printf("%d", i + 1);
			break;
		}
	}
}
