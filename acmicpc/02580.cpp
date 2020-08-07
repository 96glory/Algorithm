#include <bits/stdc++.h>
#define LENGTH 9
using namespace std;

int sudoku[10][10];
queue<pair<int, int>> zero;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i = 1; i <= LENGTH; i++){
		for(int j = 1; j <= LENGTH; j++){
			cin >> sudoku[i][j];
			if(sudoku[i][j] == 0){
				zero.push(make_pair(i, j));
			}
		}
	}
	
	while(!zero.empty()){
		int x = zero.front().first;
		int y = zero.front().second;
		
		
	}
	
}

