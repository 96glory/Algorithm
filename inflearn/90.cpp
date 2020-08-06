#include <bits/stdc++.h>
using namespace std;

struct State{
	int x, y, dis;
	State(int a, int b, int c){
		x = a; y = b; dis = c;
	}
	bool operator < (const State & b) const {
		if(dis == b.dis){
			// prior 3
			if(x = b.x) return y > b.y;
			// prior 2
			else return x > b.x;
		}
		// prior 1
		else return dis > b.dis;
	}
};

struct Lion{
	int x, y, s, ate;
	void sizeUp(){
		ate = 0;
		s++;
	}
};

int arr[21][21], ch[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
	int n, i, j, answer = 0;
	priority_queue<State> Q;
	Lion Simba;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 9){
				simba.x = i;
				simba.y = j;
				arr[i][j] = 0;
			}
		}
	}
	
	Q.push(State(simba.x, simba.y, 0));
	simba.s = 2;
	simba.ate = 0;
	while(!Q.empty()){
		State tmp = Q.top();
		Q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis;
		
		if(arr[x][y] != 0 && arr[x][y] < simba.s){
			simba.x = x;
			simba.y = y;
			simba.ate++;
			
			if(simba.ate >= simba.s) simba.sizeUp();
			arr[x][y] = 0;
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					ch[i][j] = 0;
			while(!Q.empty()) Q.pop();
			answer = z;
		}
		
		for(i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx < 1 || xx > n || yy < 1 || yy > n
					|| arr[xx][yy] > simba.s || ch[xx][yy] > 0)
				continue;
			Q.push(State(xx, yy, z + 1));
			ch[xx][yy] = 1;
		}
	}
	printf("%d", answer);
}
