#include <bits/stdc++.h>
using namespace std;

int cases, n, m, t1, t2;
vector<int> arr;

int Find(int a){
	if(a == arr[a])	return a;
	else	return arr[a] = Find(arr[a]);
}

void Union(int a, int b){
	int pa = Find(a);
	int pb = Find(b);
	if(a != b){
		if(b < a)	arr[a] = pb;	
		else		arr[b] = pa;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> cases;
	while(cases--){
		cin >> n >> m;
		arr.assign(n + 1, 0);
		for(int i = 1; i <= n; i++)
			arr[i] = i;
		
		for(int i = 1; i <= m; i++){
			cin >> t1 >> t2;
			Union(t1, t2);
		}
		sort(arr.begin(), arr.end());
		arr.erase(unique(arr.begin(), arr.end()), arr.end());
		cout << arr.size() - 1 << endl;
		arr.clear();
	}
}
