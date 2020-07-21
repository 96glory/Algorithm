#include <bits/stdc++.h>
using namespace std;

int arr[9][9], answer;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue< pair< pair<int, int>, int> > q;

int main(){
	for(int i = 1; i <= 7; i++)
		for(int j = 1; j <= 7; j++)
			scanf("%d", &arr[i][j]);
			
	q.push(make_pair(make_pair(1, 1), 0));
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cost = q.front().second;
		q.pop();
		
		if(x == 7 && y == 7){
			printf("%d", cost);
			exit(0);
		}
		
		for(int i = 0; i < 4; i++){
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			
			if(nextX >= 1 && nextX <= 7 && nextY >= 1 && nextY <= 7 && arr[nextX][nextY] == 0){
				q.push(make_pair(make_pair(nextX, nextY), cost + 1));
			}
		}
	}
}

