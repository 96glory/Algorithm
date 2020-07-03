#include <iostream>

using namespace std;

int arr[101];
int _rank[101];

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
		_rank[i] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(arr[i] > arr[j])			_rank[j]++;
			else if(arr[i] < arr[j])	_rank[i]++;
		}
	}
	
	for(int i = 1; i <= n; i++)
		printf("%d ", _rank[i]);
}

