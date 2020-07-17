#include <iostream>
#include <queue>
using namespace std;

vector<int> map[8];
queue<int> q;
int visit[8];

void bfs(){
	q.push(1);
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		printf("%d ", temp);
		visit[temp] = 1;
		
		for(auto k : map[temp]){
			if(visit[k] == 0)	q.push(k);
		}
	}
}

int main(){
	int x, y;
	for(int i = 1; i <= 6; i++){
		scanf("%d %d", &x, &y);
		map[x].push_back(y);
	}
	bfs();
}

