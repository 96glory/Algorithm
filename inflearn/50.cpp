#include <iostream>

using namespace std;

int arr[51][51];


int main(){
	int width, height, sum = 0, w, h, max = -1, i, j, k, l;
	scanf("%d", &height);	scanf("%d", &width);
	for(int i = 1; i <= height; i++){
		for(int j = 1; j <= width; j++){
			scanf("%d", &arr[i][j]);
		}
	}			
	scanf("%d", &h);	scanf("%d", &w);
	
	for(i = 1; i <= height - h + 1; i++){
		for(j = 1; j <= width - w + 1; j++){
			sum = 0;
			for(k = i; k < i + h; k++){
				for(l = j; l < j + w; l++){
					sum += arr[k][l];
				}
			}	
			if(max < sum)	max = sum;
		}
	}
	printf("%d", max);
}

