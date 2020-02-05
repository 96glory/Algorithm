#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

bool visited[100001];
int N, M;

int bfs(){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, N));
	visited[N] = true;
	
	while(!q.empty()){
		int time = q.top().first;
		int location = q.top().second;
		q.pop();
		
		if(location == M)	return time;
		
		if(location * 2 <= 100000 && !visited[location * 2]){
			q.push(make_pair(time, location * 2));
			visited[location * 2] = true;
		}
		if(location + 1 <= 100000 && !visited[location + 1]){
			q.push(make_pair(time + 1, location + 1));
			visited[location + 1] = true;
		}
		if(location - 1 >= 0 && !visited[location - 1]){
			q.push(make_pair(time + 1, location - 1));
			visited[location - 1] = true;
		}
	}
}

int main(){
	cin >> N >> M;
	cout << bfs();
}
