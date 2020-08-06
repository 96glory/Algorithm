#include <iostream>

using namespace std;

int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};
int arr[52][52];
int n;

int main(){
	int answer = 0, flag;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			flag = 0;
			for(int k = 0; k < 4; k++){
				if(arr[xx[k] + i][yy[k] + j] >= arr[i][j]){
					flag = 1;
					break;
				}
			}
			if(flag == 0)	answer++;
		}
	}
	printf("%d", answer);
}
