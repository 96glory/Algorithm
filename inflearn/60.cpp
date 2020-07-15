#include <iostream>

using namespace std;

int n, flag, arr[11], classify[11];

void dfs(int index){
	if(flag == 1)	return;
	if(index == n){
		int left = 0, right = 0;
		for(int i = 1; i <= n; i++){
			if(classify[i] == 0)
				right += arr[i];
			else
				left += arr[i];
		}
		if(left == right)	flag = 1;
		return;
	}
	else{
		classify[index] = 1;
		dfs(index + 1);
		classify[index] = 0;
		dfs(index + 1);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)	scanf("%d", &arr[i]);
	dfs(1);
	if(flag == 1)	printf("YES");
	else	printf("NO");
}

