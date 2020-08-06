#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<bool> infect;

void dfs(int start){
	infect[start] = true;
	int vSize = v[start].size();
	for(int i = 0; i < vSize; i++){
		int next = v[start][i];
		if(infect[next] == false){
			dfs(next);
		}
	}
}

int main(){
	int numComputer;	cin >> numComputer;

	v.assign(numComputer + 1, vector<int>(numComputer + 1));
	infect.assign(numComputer + 1, false);
	
	int numEdge;		cin >> numEdge;
	int left, right;
	for(int i = 0; i < numEdge; i++){
		scanf("%d %d", &left, &right);
		
		v[left].push_back(right);
		v[right].push_back(left);
	}
	
	dfs(1);	
	
	int answer = 0;
	for(int i = 1; i <= numComputer; i++){
		if(infect[i] == true)	answer++;
	}
	
	cout << answer - 1;
}
