#include <iostream>
using namespace std;

int arr[21][21], visit[21], n, m, answer = 2147000000;

void dfs(int index, int sum){
	visit[index] = 1;
	if(index == n){
		if(answer > sum)	answer = sum;
		return;
	}
	else{
		for(int i = 1; i <= n; i++){
			if(arr[index][i] != 0 && visit[i] == 0){
				dfs(i, sum + arr[index][i]);
				visit[i] = 0;
			}
		}
	}
}

int main(){
	int x, y, cost;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &x, &y, &cost);
		arr[x][y] = cost;
	}
	dfs(1, 0);
	printf("%d", answer);
}

