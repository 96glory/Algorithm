#include <bits/stdc++.h>
using namespace std;

int n, m, answer = -1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> arr;
vector<pair<int, int>> virus;
vector<pair<int, int>> emp;
vector<int> comb;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	arr.assign(n + 2, vector<int>(m + 2, 0));
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 2)	virus.push_back(make_pair(i, j));
			if(arr[i][j] == 0)	emp.push_back(make_pair(i, j));
		}
	}
	
	for(int i = 1; i <= emp.size() - 3; i++)
		comb.push_back(0);
	for(int i = 1; i <= 3; i++)
		comb.push_back(1);
	
	sort(comb.begin(), comb.end());
	
	do {
		queue<pair<int, int>> q;
		vector<vector<int>> temp = arr;
		vector<pair<int, int>> wall;
		int cnt = 0;
		
		for(int i = 0; i < comb.size(); i++){
			if(comb[i] == 1)
				wall.push_back(emp[i]);
		}
				
		for(int i = 0; i < 3; i++)
			temp[wall[i].first][wall[i].second] = 1;
		for(auto v : virus)
			q.push(v);
		
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			temp[x][y] = 2;
			for(int i = 0; i < 4; i++){
				int xx = x + dx[i];
				int yy = y + dy[i];
				
				if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && temp[xx][yy] == 0)
					q.push(make_pair(xx, yy));
			}
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(temp[i][j] == 0)	cnt++;
			}
		}
		
		answer = max(answer, cnt);
		
	} while(next_permutation(comb.begin(), comb.end()));
	
	cout << answer;
}

