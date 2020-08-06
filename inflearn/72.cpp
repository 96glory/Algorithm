#include <iostream>
#include <queue>
using namespace std;

int n, k;

int main(){
	queue<int> Q;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++)	Q.push(i);
	
	while(Q.size() > 1){
		for(int i = 1; i < k; i++){
			Q.push(Q.front());
			Q.pop();
		}
		Q.pop();
	}
	
	printf("%d", Q.front());
}

