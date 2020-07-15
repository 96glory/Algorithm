#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void preorder(int v){
	if(v > 7)	return;
	else{
		printf("%d ", v);
		preorder(v * 2); // 왼쪽 자식 노드 
		preorder(v * 2 + 1); // 오른쪽 자식 노드
	}
}

void inorder(int v){
	if(v > 7)	return;
	else{
		inorder(v * 2); // 왼쪽 자식 노드 
		printf("%d ", v);
		inorder(v * 2 + 1); // 오른쪽 자식 노드
	}
}

void postorder(int v){
	if(v > 7)	return;
	else{
		postorder(v * 2); // 왼쪽 자식 노드 
		postorder(v * 2 + 1); // 오른쪽 자식 노드
		printf("%d ", v);
	}
}

int main(){
	preorder(1);	printf("\n");
	inorder(1);		printf("\n");
	postorder(1);	printf("\n");
}

