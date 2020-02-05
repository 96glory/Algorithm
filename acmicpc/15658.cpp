#include <iostream>
#include <cmath>

using namespace std;

int N;
int arr[100];
int MAX = -1000000000;
int MIN = 1000000000;
int _add, _min, _mul, _div;

void dfs(int depth, int result){
	if(depth == N){
		MAX = max(MAX, result);
		MIN = min(MIN, result);
		return;
	}
	
	if(_add > 0){
		_add--;
		dfs(depth + 1, result + arr[depth]);
		_add++;
	}
	if(_min > 0){
		_min--;
		dfs(depth + 1, result - arr[depth]);
		_min++;
	}
	if(_mul > 0){
		_mul--;
		dfs(depth + 1, result * arr[depth]);
		_mul++;
	}
	if(_div > 0 && arr[depth] != 0){
		_div--;
		dfs(depth + 1, result / arr[depth]);
		_div++;
	}
}


int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> _add >> _min >> _mul >> _div;
	
	dfs(1, arr[0]);
	
	cout << MAX << endl << MIN;
}

