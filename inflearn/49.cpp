#include <iostream>

using namespace std;

int arr[11][11];
int front[11];
int side[11];

int main(){
	int n, sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)	scanf("%d", &front[i]);
	for(int i = 1; i <= n; i++)	scanf("%d", &side[i]);
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			arr[i][j] = front[j];
			
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= n; j++){
			if(arr[i][j] > side[n - i + 1]){
				arr[i][j] = side[n - i + 1];
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			sum += arr[i][j];
	
	printf("%d", sum);
}

