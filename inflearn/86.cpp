#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > pizza;
vector< pair<int, int> > house;
int ch[20], n, m, a, answer = 2147000000;

void dfs(int L, int s){
	if(L == m){
		int sum = 0;
		for(int i = 0; i < house.size(); i++){
			int x1 = house[i].first;
			int y1 = house[i].second;
			int distance = 2147000000;
			for(int j = 0; j < m; j++){
				int x2 = pizza[ch[j]].first;
				int y2 = pizza[ch[j]].second;
				distance = min(distance, abs(x1 - x2) + abs(y1 - y2));
			}
			sum += distance;
		}
		if(sum < answer) answer = sum;
	}
	else{
		for(int i = s; i < pizza.size(); i++){
			ch[L] = i;
			dfs(L + 1, i + 1);
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &a);
			if(a == 1) house.push_back(make_pair(i, j));
			if(a == 2) pizza.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0);
	printf("%d", answer);
}

