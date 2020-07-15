#include <iostream>

using namespace std;

int n;

void recursive(int index){
	if(index > n)	return;
	printf("%d ", index);
	recursive(index + 1);
}

int main(){
	scanf("%d", &n);
	recursive(1);
}

