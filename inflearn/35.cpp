#include <iostream>
#include <vector>

using namespace std;

int arr[101];
vector<int> neg;
vector<int> pos;

int main(){
	int n, temp;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &temp);
		if(temp > 0)		pos.push_back(temp);
		else if(temp < 0)	neg.push_back(temp);
	}
	
	for(auto k : neg)	printf("%d ", k);
	for(auto k : pos)	printf("%d ", k);
}

