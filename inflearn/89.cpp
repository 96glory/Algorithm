#include <bits/stdc++.h>

using namespace std;

struct Tomato{
	int x;
	int y;
	Tomato(int a, int b){
		x = a; y = b;
	}
};

queue<Tomato> q;
int m, n, arr[1002][1002], result[1002][1002], answer = -2147000000;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int status[3];

int main(){
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 1){
				q.push(Tomato(i, j));
				status[2]++;
			}
			else if(arr[i][j] == 0)
				status[1]++;
			else
				status[0]++;
		}
	}
	
	if(status[1] == 0){
		printf("0");
		exit(0);
	}
	
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m
					&& arr[xx][yy] == 0){
				arr[xx][yy] = 1;
				result[xx][yy] = result[x][y] + 1;
				q.push(Tomato(xx, yy));
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(arr[i][j] == 0){
				printf("-1");
				exit(0);
			}
			answer = max(answer, result[i][j]);
		}
	}
	printf("%d", answer);
}

