#include <iostream>

using namespace std;

int arr[101];
bool check[101];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i = 1; i < n; i++){
		check[abs(arr[i] - arr[i + 1])] = true;
	}
	for(int i = 1; i < n; i++){
		if(!check[i]){
			printf("NO");
			return 0;
		}
	}
	
	printf("YES");
}

