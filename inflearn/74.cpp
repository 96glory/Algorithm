#include <iostream>
#include <queue>

using namespace std;

int main(){
	priority_queue<int, vector<int>, greater<int>> pq;
	int temp;
	while(-1){
		scanf("%d", &temp);
		if(temp == -1) break;
		else if(temp == 0){
			if(pq.empty())	printf("-1\n");
			else{
				printf("%d\n", pq.top());
				pq.pop();	
			}
		}
		else pq.push(temp);
	}
}

