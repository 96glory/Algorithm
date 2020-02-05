#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
bool visited[1000001];
int N, M, answer = 987654321;

int bfs(){
	if(N == M)	return 0;
	if(N > M)	return N - M;
	
	visited[N] = true;
	if(N - 1 >= 0){
		visited[N - 1] = true;
		q.push(make_pair(N - 1, 1));	
	}
	if(N + 1 <= 100000){
		visited[N + 1] = true;
		q.push(make_pair(N + 1, 1));	
	}
	if(N * 2 <= 100000){
		visited[N * 2] = true;
		q.push(make_pair(N * 2, 1));	
	}
	while(!q.empty()){
		int location = q.front().first;
		int time = q.front().second;
		q.pop();
		
		if(location == M)	return time;
		if(time >= answer)	continue;
		
		if(!visited[location - 1] && location - 1 >= 0){
			visited[location - 1] = true;
			q.push(make_pair(location - 1, time + 1));
		}
		if(!visited[location + 1] && location + 1 <= 100000){
			visited[location + 1] = true;
			q.push(make_pair(location + 1, time + 1));
		}
			
		if(!visited[location * 2] && location * 2 <= 100000){
			visited[location * 2] = true;
			q.push(make_pair(location * 2, time + 1));
		}
	}
}

int main(){
	cin >> N >> M;
	cout << bfs();
}

