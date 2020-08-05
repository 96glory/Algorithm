#include <bits/stdc++.h>
using namespace std;

int cnt, N, r, c;

void dc(int size, int x, int y){
	if(size == 1){
		if(x == r && y == c){
			cout << cnt;
			exit(0);
		}
		cnt++;
	}
	else{
		if(x <= r && r <= x + size / 2 && y <= c && c <= y + size / 2)
			dc(size / 2, x, y);
		else
			cnt += pow((size / 2), 2);
		
		if(x <= r && r <= x + size / 2 && y + (size / 2) <= c && c <= y + size)
			dc(size / 2, x, y + (size / 2));
		else
			cnt += pow((size / 2), 2);
		
		if(x + (size / 2) <= r && r <= x + size && y <= c && c <= y + size / 2)
			dc(size / 2, x + (size / 2), y);
		else
			cnt += pow((size / 2), 2);
		
		if(x + (size / 2) <= r && r <= x + size && y + (size / 2) <= c && c <= y + size)
			dc(size / 2, x + (size / 2), y + (size / 2));
		else
			cnt += pow((size / 2), 2);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	
	cin >> N >> r >> c;
	dc(pow(2, N), 0, 0);
}
