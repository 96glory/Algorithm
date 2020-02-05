#include <iostream>

using namespace std;

int N, M, answer;
bool arr[1001][1001];
bool check[1001];

void dfs(int v){
	if(check[v])	return;
	check[v] = true;
	for(int i = 1; i <= N; i++){
		if(arr[i][v])	dfs(i);
	}
}

int isEnd(){
	for(int i = 1; i <= N; i++){
		if(!check[i])	return i;
	}
	return -1;
}

int main(){
	cin >> N >> M;
	int a, b;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		arr[a][b] = arr[b][a] = true;
	}
	
	while(-1){
		int v = isEnd();
		if(v == -1)	break;
		
		dfs(v);
		answer++;
	}
	
	cout << answer;
}
