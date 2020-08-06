#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	while(b != 0){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int sit, m, n, x, y, limit, flag;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> sit;
	for(int i = 1; i <= sit; i++){
		cin >> m >> n >> x >> y;
		
		flag = 0;
		limit = lcm(m, n);
		
		for(int j = x; j <= limit ; j += m){
			if(j % n == y % n){
				flag = 1;
				cout << j << endl;
				break;
			}
		}
		if(flag == 0){
			cout << "-1" << endl;
		}
	}
}
