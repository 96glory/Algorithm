#include <bits/stdc++.h>
#define LENGTH 9
using namespace std;

int sudoku[10][10], zeroNum;
vector<pair<int, int>> zero;

int square(int a, bool en){
	if(a >= 1 && a <= 3){
		if(en)	return 3;
		else	return 1;
	}
	if(a >= 4 && a <= 6){
		if(en)	return 6;
		else	return 4;
	}
	if(a >= 7 && a <= 9){
		if(en)	return 9;
		else	return 7;
	}
}

bool promising(int a, int b){
	int cntA[10] = {0, }, cntB[10] = {0, }, cntSquare[10] = {0, };
	
	for(int i = 1; i <= LENGTH; i++){
		cntA[sudoku[a][i]]++;
		cntB[sudoku[i][b]]++;
	}
	
	for(int i = square(a, 0); i <= square(a, 1); i++){
		for(int j = square(b, 0); j <= square(b, 1); j++){
			cntSquare[sudoku[i][j]]++;
		}
	}
	
	for(int i = 1; i <= LENGTH; i++){
		if(cntA[i] >= 2 || cntB[i] >= 2 || cntSquare[i] >= 2){
			return false;
		}
	}
	return true;
}

void bt(int level){
	if(level == zeroNum - 1){
		for(int i = 1; i <= LENGTH; i++){
			for(int j = 1; j <= LENGTH; j++){
				cout << sudoku[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	else {
		for(int i = 1; i <= LENGTH; i++){
			sudoku[zero[level + 1].first][zero[level + 1].second] = i;
			if(promising(zero[level + 1].first, zero[level + 1].second)){
				bt(level + 1);
			}
			sudoku[zero[level + 1].first][zero[level + 1].second] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i = 1; i <= LENGTH; i++){
		for(int j = 1; j <= LENGTH; j++){
			cin >> sudoku[i][j];
			if(sudoku[i][j] == 0){
				zero.push_back(make_pair(i, j));
				zeroNum++;
			}
		}
	}
	
	bt(-1);
}

