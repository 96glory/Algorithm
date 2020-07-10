#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main(){
	int n; scanf("%d", &n);
	int idx2 = 0, idx3 = 0, idx5 = 0, res2 = 0, res3 = 0, res5 = 0;
	
	arr.push_back(1);
	while(arr.size() < n){
		res2 = arr[idx2] * 2;
		res3 = arr[idx3] * 3;
		res5 = arr[idx5] * 5;
		arr.push_back(min(min(res2, res3), res5));
		
		if(*(arr.end() - 1) == res2)	idx2++;
		if(*(arr.end() - 1) == res3)	idx3++;
		if(*(arr.end() - 1) == res5)	idx5++;
	}
	printf("%d", arr.at(n - 1));
}
