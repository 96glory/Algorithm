#include <iostream>

using namespace std;

int n, m, arr[11], answer;

void dfs(int index, int sum){
	if(index > n){
		if(sum == m)	answer++;
		return;
	}
	else{
		dfs(index + 1, sum + arr[index]);
		dfs(index + 1, sum - arr[index]);
		dfs(index + 1, sum);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	dfs(1, 0);
	if(answer != 0) printf("%d", answer);
	else printf("-1");
}

