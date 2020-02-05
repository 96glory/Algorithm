#include <iostream>
#include <queue>

using namespace std;

int S, answer = 987654321;
queue<pair<int, int>> q;
int v[2001][2001];

void bfs(){
	q.push(make_pair(1, 0));
	while(!q.empty()){
		int num = q.front().first;
		int clip = q.front().second;
		q.pop();
		
		if(num == S){
			answer = v[num][clip];
			return;
		}
		
		int x[] = {num, num + clip, num - 1};
		int y[] = {num, clip, clip};
		
		for(int i = 0; i < 3; i++){
			if(x[i] < 0 || x[i] > 2 * S)	continue;
			if(v[x[i]][y[i]])				continue;
			v[x[i]][y[i]] = v[num][clip] + 1;
			q.push(make_pair(x[i], y[i]));
		}
	}
}

int main(){
	cin >> S;
	bfs();
	cout << answer;
}

