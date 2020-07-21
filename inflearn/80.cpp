#include <bits/stdc++.h>
#define MAX_DIS 2147000000

using namespace std;

struct Edge{
	int vertex;
	int distance;
	
	Edge(int a, int b){
		vertex = a;
		distance = b;
	}
	
	bool operator < (const Edge & b) const {
		return distance > b.distance;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	
	int i, n, m, a, b, c;
	priority_queue<Edge> PQ;
	vector< pair<int, int> > graph[30];
	
	cin >> n >> m;
	vector<int> dist(n + 1, MAX_DIS);
	
	for(i = 1; i <= m; i++){
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	
	PQ.push(Edge(1, 0));
	dist[1] = 0;
	while(!PQ.empty()){
		int now = PQ.top().vertex;
		int cost = PQ.top().distance;
		PQ.pop();
		
		if(cost > dist[now]) continue;
		for(i = 0; i < graph[now].size(); i++){
			int next = graph[now][i].first;
			int nextDis = cost + graph[now][i].second;
			if(dist[next] > nextDis){
				dist[next] = nextDis;
				PQ.push(Edge(next, nextDis));
			}
		}
	}
	
	for(i = 2; i <= n; i++){
		if(dist[i] != MAX_DIS)	cout << i << " : " << dist[i] << endl;
		else	cout << i << " : impossible" << endl;
	}
}
