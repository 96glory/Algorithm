#include <iostream>

using namespace std;

int arr[10001];
int _rank[10001];

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	
	_rank[1] = 1;
	for(int i = 2; i <= n; i++){
		int cnt = 1;
		for(int j = 1; j <= i - 1; j++){
			if(arr[j] >= arr[i]){
				cnt++;
			}
		}
		_rank[i] = cnt;
	}
	
	for(int i = 1; i <= n; i++){
		printf("%d ", _rank[i]);
	}
}

