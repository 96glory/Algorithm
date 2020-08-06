#include <iostream>
using namespace std;

int arr[21][21], visit[21], n, m, answer;

void dfs(int index){
	visit[index] = 1;
	if(index == n){
		answer++;
		return;
	}
	else{
		for(int i = 1; i <= n; i++){
			if(arr[index][i] == 1 && visit[i] == 0){
				dfs(i);
				visit[i] = 0;
			}
		}
	}
}

int main(){
	int x, y;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
	}
	dfs(1);
	printf("%d", answer);
}

