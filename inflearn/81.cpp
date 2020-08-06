#include <bits/stdc++.h>
#define DIS_MAX 2147000000

using namespace std;

int dist[101];
struct Edge{
	int start;
	int end;
	int val;
	Edge(int a, int b, int c){
		start = a;
		end = b;
		val = c;
	}
};

int main(){
	int i, n, m, a, b, c, j, s, e;
	vector<Edge> Ed;
	
	for(i = 1; i <= m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));
	}
	for(i = 1; i <= n; i++)
		dist[i] = DIS_MAX;
	
	scanf("%d %d", &s, &e);
	dist[s] = 0;
	
	// ������ ���� 
	for(i = 1; i < n; i++){
		// ��� ������ ���� ���� 
		for(j = 0; j < Ed.size(); j++){
			int u = Ed[j].start;
			int v = Ed[j].end;
			int w = Ed[j].val;
			if(dist[u] != DIS_MAX && dist[u] + w < dist[v]) 
				dist[v] = dist[u] + w;
		}
	}
	
	// ���� ����Ŭ�� �ִ� �� ���. n ��° ������ �߰����� �� �ּ� ����� ������ ���� �ִ°��� �˻�. 
	for(j = 0; j < Ed.size(); j++){
		int u = Ed[j].start;
		int v = Ed[j].end;
		int w = Ed[j].val;
		if(dist[u] != DIS_MAX && dist[u] + w < dist[v]){
			printf("-1");
			exit(0);
		}
	}
	printf("%d", dist[e]);
}
