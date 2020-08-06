//// 0번으로 시작하는 숫자 N개 중 R개를 조합으로 뽑는 방법 
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, r;
//int ch[20];
//
//void dfs(int s, int L){
//	if(L == r){
//		for(int i = 0; i < r; i++)
//			printf("%d ", ch[i]);
//		printf("\n");
//	}
//	else{
//		for(int i = s; i < n; i++){
//			ch[L] = i;
//			dfs(i + 1, L + 1);
//		}
//	}
//}
//
//int main(){
//	cin >> n >> r;
//	dfs(0, 0);
//}

#include <bits/stdc++.h>
using namespace std;

int n, r;

int main (){
	cin >> n >> r;
	vector<int> v, ind;
	for(int i = 0; i < n ; i++)
		v.push_back(i);
	for(int i = 0; i < r; i++)
		ind.push_back(0);
	for(int i = 0; i < n - r; i++)
		ind.push_back(1);
	sort(ind.begin(), ind.end());
	
	do{
		for(int i = 0; i < n; i++){
			if(ind[i] == 0)
				printf("%d ", v[i]);
		}
		printf("\n");
	}while(next_permutation(ind.begin(), ind.end()));
}
