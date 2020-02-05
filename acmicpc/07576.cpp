#include <iostream>
#include <queue>

using namespace std;

int N, M, cnt, answer;
int arr[1000][1000];
int xx[4] = {1, -1, 0, 0};
int yy[4] = {0, 0, 1, -1};
queue<pair<pair<int, int>, int>> q;

bool check(){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(arr[i][j] == 0)	return false;
		}
	}
	return true;
}

void bfs(){
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int days = q.front().second;
		answer = days;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int X = x + xx[i];
			int Y = y + yy[i];
			
			if(X < 0 || Y < 0 || X >= M || Y >= N)	continue;
			if(arr[X][Y] == 1 || arr[X][Y] == -1)	continue;
			if(arr[X][Y] == 0){
				arr[X][Y] = 1;
				q.push(make_pair(make_pair(X, Y), days + 1));
			}
		}			
	}	
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 1)
				q.push(make_pair(make_pair(i, j), 0));
			else if(arr[i][j] == -1)
				cnt++;
		}
	}

	if(q.size() + cnt == N * M){
		cout << "0";
		return 0;
	}
	bfs();
	if(!check())	cout << "-1";
	else			cout << answer;
}

