#include <iostream>
#include <vector>

using namespace std;

vector< pair<int, int> > arr[21];
int visit[21], n, m, answer = 2147000000;

void dfs(int index, int sum){
	visit[index] = 1;
	if(index == n){
		if(answer > sum)	answer = sum;
		return;
	}
	else{
		for(auto k : arr[index]){
			if(visit[k.first] == 0){
				dfs(k.first, sum + k.second);
				visit[k.first] = 0;
			}
		}
	}
}

int main(){
	int x, y, cost;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &x, &y, &cost);
		arr[x].push_back(make_pair(y, cost));
	}
	dfs(1, 0);
	printf("%d", answer);
}

