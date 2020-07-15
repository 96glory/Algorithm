#include <iostream>
using namespace std;

int arr[21][21], n, m;

int main(){
	int x, y, cost;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &x, &y, &cost);
		arr[x][y] = cost;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

