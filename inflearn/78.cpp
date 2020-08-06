#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int unified[10001];

struct Edge{
	int v1;
	int v2;
	int cost;
	
	Edge(int a, int b, int c){
		v1 = a; v2 = b; cost = c;
	}
	
	bool operator < (Edge & b){
		return cost < b.cost;
	}
};

int Find(int v){
	if(v == unified[v]) return v;
	else return unified[v] = Find(unified[v]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a != b) unified[a] = b;
}

int main(){
	vector<Edge> E;
	int i, n, m, a, b, c, cnt = 0, answer = 0;
	
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++)
		unified[i] = i;
	for(i = 1; i <= m; i++){
		scanf("%d %d %d", &a, &b, &c);
		E.push_back(Edge(a, b, c));
	}
	sort(E.begin(), E.end());
	
	for(i = 0; i < m; i++){
		int pa = Find(E[i].v1);
		int pb = Find(E[i].v2);
		if(pa != pb){
			answer += E[i].cost;
			Union(E[i].v1, E[i].v2);
		}
	}
	printf("%d", answer);
}
