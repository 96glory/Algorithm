#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr1;
vector<int> arr2;
vector<int> answer;

int main(){
	int n, m, temp, _n = 0, _m = 0;
	
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
	
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	
	while(_n < n && _m < m){
		if(arr1[_n] > arr2[_m])			_m++;
		else if(arr1[_n] < arr2[_m])	_n++;
		else{
			answer.push_back(arr1[_n]);
			_n++;
			_m++;
		}
	}
	
	for(auto k : answer)
		printf("%d ", k);
	
}

