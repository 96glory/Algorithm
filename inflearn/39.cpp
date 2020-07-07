#include <iostream>
#include <vector>

using namespace std;

vector<int> arr1;
vector<int> arr2;
vector<int> answer;

int main(){
	int n, m, temp;
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &temp);
		arr1.push_back(temp);
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		scanf("%d", &temp);
		arr2.push_back(temp);
	}
	
	int _n = 0, _m = 0;
	while(_n < n && _m < m){
		if(arr1[_n] > arr2[_m]){
			answer.push_back(arr2[_m]);
			_m++;
		}
		else if(arr1[_n] < arr2[_m]){
			answer.push_back(arr1[_n]);
			_n++;
		}
		else{
			answer.push_back(arr1[_n]);
			answer.push_back(arr2[_m]);
			_n++;
			_m++;
		}
	}
	
	if(_n == n){
		for(int i = _m; i < m; i++)
			answer.push_back(arr2[i]);
	}
	else if(_m == m){
		for(int i = _n; i < n; i++)
			answer.push_back(arr1[i]);
	}
	
	for(auto k : answer)
		printf("%d ", k);
	
}

