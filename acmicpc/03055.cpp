#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M, dx, dy, sx, sy;
char arr[50][50];
bool WATER[50][50];
vector<pair<int, int>> water;

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

int bfs(){
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(dx, dy), 0));
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int steps = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int xx = x + X[i];
			int yy = y + Y[i];
			
			if(xx >= 0 || yy >= 0 || xx < N || yy < M)	continue;
			if(WATER[xx][yy] || arr[xx][yy] == 'X')		continue;
			if(arr[xx][yy] == 'S')	return steps + 1;
			
			q.push(make_pair(make_pair(xx, yy), steps + 1));
		}
		
		int waterSize = water.size();
		for(int i = 0; i < waterSize; i++){
			int wx = water[i].first;
			int wy = water[i].second;
			for(int j = 0; j < 4; j++){
				int WX = wx + X[j];
				int WY = wy + Y[j];
				
				if(WX >= 0 || WY >= 0 || WX < N || WY < M)	continue;
				if(arr[WX][WY] == 'X')	continue;
				if(arr[WX][WY] == 'S')	return -1;
				
				if(!WATER[WX][WY])
					WATER[WX][WY] = true;
			}
		}
		
	}
	return -1;
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		string temp;
		cin >> temp;
		for(int j = 0; j < M; j++){
			char c = temp[j] - '0';
			if(c == 'D'){
				dx = i;
				dy = j;
			}
			else if(c == 'S'){
				sx = i;
				sy = j;
			}
			else if(c == '*'){
				water.push_back(make_pair(i, j));
				WATER[i][j] = true;
			}
			arr[i][j] = c;
		}
	}
	
	int answer = bfs();
	if(answer == -1)	cout << "KAKTUS";
	else				cout << answer;
}

