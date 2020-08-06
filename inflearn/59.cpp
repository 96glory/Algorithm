#include <iostream>

using namespace std;

int visit[11], n;

void dfs(int index){
	if(index == n){
		for(auto k: visit){
			if(k != 0)	printf("%d ", k);
		}
		printf("\n");
		return;
	}
	else{
		visit[index + 1] = index + 1;
		dfs(index + 1);
		visit[index + 1] = 0;
		dfs(index + 1);
	}
	
}


int main(){
	scanf("%d", &n);
	dfs(0);
}
