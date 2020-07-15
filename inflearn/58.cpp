#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void preorder(int v){
	if(v > 7)	return;
	else{
		printf("%d ", v);
		preorder(v * 2); // ���� �ڽ� ��� 
		preorder(v * 2 + 1); // ������ �ڽ� ���
	}
}

void inorder(int v){
	if(v > 7)	return;
	else{
		inorder(v * 2); // ���� �ڽ� ��� 
		printf("%d ", v);
		inorder(v * 2 + 1); // ������ �ڽ� ���
	}
}

void postorder(int v){
	if(v > 7)	return;
	else{
		postorder(v * 2); // ���� �ڽ� ��� 
		postorder(v * 2 + 1); // ������ �ڽ� ���
		printf("%d ", v);
	}
}

int main(){
	preorder(1);	printf("\n");
	inorder(1);		printf("\n");
	postorder(1);	printf("\n");
}

