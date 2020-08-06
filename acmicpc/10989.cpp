#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main(){
	vector<int> v(10001, 0);
	int N;	cin >> N;
	
	int temp;
	for(int i = 0; i < N; i++){
		scanf("%d", &temp);
		v[temp]++;
	}
	
	for(int i = 1; i <= 10000; i++){
		if(v[i] == 0)	continue;
		else{
			for(int j = 0; j < v[i]; j++){
				printf("%d\n", i);
			}
		}
	}
}

