#include <bits/stdc++.h>

using namespace std;

int n, r, result;
vector<int> arr(16, 0);
vector<bool> visit(16, false);
vector<int> answer(16, 0);

void dfs(int level){
	if(level == r){
		for(int i = 1; i <= r; i++){
			printf("%d ", arr[answer[i]]);
		}
		printf("\n");
		result++;
	}
	else{
		for(int i = 1; i <= n; i++){
			if(visit[i]) continue;
			visit[i] = true;
			answer[level + 1] = i;
			dfs(level + 1);
			visit[i] = false;
			answer[level + 1] = 0;
		}
	}
}

int main(){
	int temp;
	scanf("%d %d", &n, &r);
	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	
	dfs(0);
	printf("%d", result);
}

