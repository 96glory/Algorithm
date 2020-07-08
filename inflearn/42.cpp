#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main(){
	int n, m, temp;
	scanf("%d", &n);	scanf("%d", &m);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	
	sort(arr.begin(), arr.end());
	
	int left = 0, right = n - 1, mid;
	do {
		mid = (left + right) / 2;
		
		if(arr[mid] == m){
			printf("%d", mid + 1);
			return 0;
		}
		else if(arr[mid] > m)	right = mid - 1;
		else if(arr[mid] < m)	left = mid + 1;
	} while(-1);
}

