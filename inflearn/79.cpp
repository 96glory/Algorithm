#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int check[30];
struct Edge{
	int e;
	int cost;
	
	Edge(int a, int b){
		e = a;
		cost = b;
	}
	
	bool operator < (const Edge & b) const {
		return cost > b.cost;
	}
};

int main(){
	priority_queue<Edge> pq;
	vector< pair<int, int> > map[30];
	
	int i, n, m, a, b, c, answer = 0;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	pq.push(Edge(1, 0));
	while(!pq.empty()){
		Edge temp = pq.top();
		pq.pop();
		int v = temp.e;
		int cost = temp.cost;
		if(check[v] == 0){
			answer += cost;
			check[v] = 1;
			for(i = 0; i < map[v].size(); i++){
				pq.push(Edge(map[v][i].first, map[v][i].second));
			}
		}
	}
	printf("%d", answer);
}
