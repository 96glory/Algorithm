#include <bits/stdc++.h>
using namespace std;

vector<char> v;
vector<int> visit;
int l, c;
char temp;

void dfs(int len, int idx){
	if(len == l){
		int con = 0, vow = 0;
		for(int i = 0; i < v.size(); i++){
			if(visit[i] == 1){
				if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
					vow++;
				else
					con++;
			}
		}
		if(con >= 2 && vow >= 1){
			for(int i = 0; i < v.size(); i++){
				if(visit[i] == 1)
					cout << v[i];
			}
			cout << endl;
		}
	}
	else{
		for(int i = idx; i < v.size(); i++){
			visit[i] = 1;
			dfs(len + 1, i + 1);
			visit[i] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> l >> c;
	for(int i = 1; i <= c; i++){
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	visit.assign(v.size(), 0);
	
	dfs(0, 0);
}

