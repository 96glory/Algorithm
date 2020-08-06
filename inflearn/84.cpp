#include <bits/stdc++.h>

using namespace std;

struct Rsv{
	int day;
	int cost;
	Rsv(int a, int b){
		day = a;
		cost = b;
	}
};

int n, answer = -2147000000;
vector<Rsv> v;

void dfs(int d, int sum){
	if(d > n){
		if(answer < sum)
			answer = sum;
	}
	else{
		if(v[d].day + d <= n + 1)
			dfs(d + v[d].day, sum + v[d].cost);
		dfs(d + 1, sum);
	}
}

int main(){
	scanf("%d", &n);
	int a, b;
	v.push_back(Rsv(0, 0));
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &a, &b);
		v.push_back(Rsv(a, b));
	}
	
	dfs(1, 0);
	printf("%d", answer);
}

