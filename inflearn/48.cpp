#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];

int main(){
	for(int i = 0; i < 9; i++){
		int avg = 0, target = 200;
		for(int j = 0; j < 9; j++){
			scanf("%d", &arr[j]);
			avg += arr[j];
		}
		
		avg *= 10;	avg /= 9;
		if(avg % 10 <= 4)	avg = avg / 10;
		else				avg = avg / 10 + 1;		
		sort(arr, arr + 8);
		
		for(int j = 0; j < 9; j++){
			if(abs(arr[j] - avg) <= abs(target - avg)){
				target = arr[j];
			}
		}
		
		printf("%d %d\n", avg, target);
	}
}

