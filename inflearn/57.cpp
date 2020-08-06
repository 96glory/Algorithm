#include <iostream>

using namespace std;

int n;

void recursive(int index){
	if(index == 0)	return;
	recursive(index / 2);
	printf("%d", index % 2);
}

int main(){
	scanf("%d", &n);
	recursive(n);
}

