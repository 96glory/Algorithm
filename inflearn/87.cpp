#include <bits/stdc++.h>
using namespace std;

int arr[22][22], n, answer;
int X[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int Y[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
queue< pair<int, int> > q;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(arr[i][j] == 1){
				q.push(make_pair(i, j));
				arr[i][j] = 0;
				
				while(!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					
					for(int k = 0; k < 8; k++){
						int nextX = x + X[k];
						int nextY = y + Y[k];
						
						if(nextX > 0 && nextX <= n && nextY > 0 && nextY <= n && arr[nextX][nextY] == 1){
							arr[nextX][nextY] = 0;
							q.push(make_pair(nextX, nextY));
						}
					}
				}
				answer++;
			}
		}
	}
	
	printf("%d", answer);
}

