#include <bits/stdc++.h>
using namespace std;

int arr[9][9], dis[9][9], answer;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Location{
	int x;
	int y;
	Location(int a, int b){
		x = a;	y = b;
	}
};

queue<Location> q;

int main(){
	for(int i = 1; i <= 7; i++)
		for(int j = 1; j <= 7; j++)
			scanf("%d", &arr[i][j]);
			
	q.push(Location(1, 1));
	arr[1][1] = 1;
	while(!q.empty()){
		Location temp = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = temp.x + dx[i];
			int yy = temp.y + dy[i];
			if(arr[xx][yy] == 0 && xx >= 1 && xx <= 7 && yy >= 1 && yy <= 7){
				q.push(Location(xx, yy));
				arr[xx][yy] = 1;
				dis[xx][yy] = dis[temp.x][temp.y] + 1;
			}
		}
	}
	printf("%d", dis[7][7]);
}

