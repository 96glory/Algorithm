#include <iostream>
#include <string>
#include <queue>
using namespace std;

int arr[100][100];
int dist[100][100];
int N, M;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(){
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dist[0][0] = 0;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= M || ny >= N)	continue;
			
			if(arr[nx][ny] == 1){
				if(dist[nx][ny] > dist[x][y] + 1){
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
			else if(arr[nx][ny] == 0){
				if(dist[nx][ny] > dist[x][y]){
					dist[nx][ny] = dist[x][y];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		string temp;
		cin >> temp;
		for(int j = 0; j < N; j++){
			arr[i][j] = temp[j] - '0';
			dist[i][j] = 987654321;
		}
	}
	
	bfs();
	cout << dist[M - 1][N - 1];
}
