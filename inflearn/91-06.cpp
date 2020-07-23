#include <bits/stdc++.h>
using namespace std;

int a, b, c, n, dp[101], answer;

struct Brick{
	int base, height, weight;
	Brick(int a, int b, int c){
		base = a; height = b; weight = c;
	}
	bool operator < (const Brick & b) const {
		return base > b.base;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<Brick> v;
	
	for(int i = 1; i <= n; i++){
		cin >> a >> b >> c;
		v.push_back(Brick(a, b, c));
	}
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++){
		int temp = 0;
		for(int j = 0; j < i; j++){
			if(v[j].weight > v[i].weight && dp[j] > temp)
				temp = dp[j];
		}
		dp[i] = temp + v[i].height;
		answer = max(answer, dp[i]);
	}
}

