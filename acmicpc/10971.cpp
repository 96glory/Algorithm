#include <stdio.h>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	
	int arr[N][N];
	int W[N][N];
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &arr[i][j]);
			W[i][j] = arr[i][j];
		}
	}

	
	
}

