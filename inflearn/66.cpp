#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[21];
int visit[21], n, m, answer;

void dfs(int index){
	visit[index] = 1;
	if(index == n){
		answer++;
		return;
	}
	else{
		for(auto k : arr[index]){
			if(visit[k] == 0){
				dfs(k);
				visit[k] = 0;
			}
		}
	}
}

int main(){
	int x, y;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &x, &y);
		arr[x].push_back(y);
	}
	dfs(1);
	printf("%d", answer);
}

