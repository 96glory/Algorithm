#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, temp;
vector<int> arr(1001);

int find(int index){
	if(arr[index] == index)	return index;
//	else return find(arr[index]);
	else return arr[index] = find(arr[index]);
}

void union(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b) arr[a] = b;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n ; i++)
		arr[i] = i;
		
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &a, &b);
		union(a, b);
	}
	
	scanf("%d %d", a, b);
	if(find(a) == find(b)) printf("YES");
	else printf("NO");
}

