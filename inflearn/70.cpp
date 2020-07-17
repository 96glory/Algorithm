#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> map[21];
queue< pair<int, int> > q;
int visit[21], answer[21], n, m;

void bfs(){
	q.push(make_pair(1, 0));
	while(!q.empty()){
		int temp = q.front().first;
		int cost = q.front().second;
		q.pop();
		visit[temp] = 1;
		if(answer[temp] > cost) answer[temp] = cost;
		
		for(auto k : map[temp]){
			if(visit[k] == 0) q.push(make_pair(k, cost + 1));
		}
	}
}

int main(){
	int x, y;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &x, &y);
		map[x].push_back(y);
	}
	for(int i = 1; i <= n; i++)
		answer[i] = 2147000000;
		
	bfs();
	
	for(int i = 2; i <= n; i++)
		printf("%d : %d\n", i, answer[i]);
}

