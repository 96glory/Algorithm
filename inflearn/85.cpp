#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int n, rmax = -2147000000, rmin = 2147000000;
// add, sub, mul, div
int op[5];

void dfs(int level, int result){
	if(level == n){
		if(result > rmax) rmax = result;
		if(result < rmin) rmin = result;
	}
	else{
		if(op[1] > 0){
			op[1]--;
			dfs(level + 1, result + arr[level]);
			op[1]++;
		}
		if(op[2] > 0){
			op[2]--;
			dfs(level + 1, result - arr[level]);
			op[2]++;
		}
		if(op[3] > 0){
			op[3]--;
			dfs(level + 1, result * arr[level]);
			op[3]++;
		}
		if(op[4] > 0){
			op[4]--;
			dfs(level + 1, result / arr[level]);
			op[4]++;
		}
	}
}

int main(){
	int temp;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	for(int i = 1; i <= 4; i++)
		scanf("%d", &op[i]);
	
	dfs(1, arr[0]);
	printf("%d\n%d", rmax, rmin);
}

