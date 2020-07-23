#include <bits/stdc++.h>
using namespace std;

int n, answer[46];
int dfs(int n){
	if(answer[n] > 0) return answer[n];
	if(n == 1 || n == 2) return n;
	else return answer[n] = dfs(n - 1) + dfs(n - 2);
}

int main(){
	scanf("%d", &n);
	printf("%d", dfs(n));
}

