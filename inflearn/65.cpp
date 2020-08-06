#include <iostream>

using namespace std;

int arr[9][9], visit[9][9], answer;
int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

void dfs(int x, int y){
	visit[x][y] = 1;
	if(x == 7 && y == 7){
		answer++;
		return;
	}
	else{
		for(int i = 0; i <= 3; i++){
			int X = x + xx[i];
			int Y = y + yy[i];
			if(X >= 1 && X <= 7 && Y >= 1 && Y <= 7
					&& arr[X][Y] == 0 && visit[X][Y] == 0){
				dfs(X, Y);
				visit[X][Y] = 0;
			}
		}
	}
}

int main(){
	for(int i = 1; i <= 7; i++)
		for(int j = 1; j <= 7; j++)
			scanf("%d", &arr[i][j]);

	dfs(1, 1);
	printf("%d", answer);
}

