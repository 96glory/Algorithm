#include <iostream>
#include <queue>

using namespace std;

int s, e, visit[10001], d[3] = {1, -1, 5};

int main(){
	int i, x, pos;
	queue<int> Q;
	scanf("%d %d", &s, &e);
	
	visit[s] = 1;
	Q.push(s);
	while(!Q.empty()){
		x = Q.front();
		Q.pop();
		
		for(i = 0; i < 3; i++){
			pos = x + d[i];
			if(pos < 1 || pos > 10000) continue;
			if(pos == e){
				printf("%d", visit[x]);
				exit(0);
			}
			if(visit[pos] == 0){
				visit[pos] = visit[x] + 1;
				Q.push(pos);
			}
		}
	}
}

