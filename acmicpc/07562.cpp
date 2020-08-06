#include <iostream>
#include <queue>

using namespace std;

int arr[300][300];
int xx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int yy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(){
	int n, length, x, y, dx, dy, curx, cury, cnt;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &length);
		scanf("%d %d", &x, &y);
		scanf("%d %d", &dx, &dy);
		
		for(int j = 0; j < length; j++)
			for(int k = 0; k < length; k++)
				arr[j][k] = 0;
		
		queue< pair < pair<int, int>, int> > q;
		q.push(make_pair(make_pair(x, y), 0));
		
		while(!q.empty()){
			curx = q.front().first.first;
			cury = q.front().first.second;
			cnt = q.front().second;
			q.pop();
			
			if(curx == dx && cury == dy){
				printf("%d\n", cnt);
				break;
			}
			
			for(int j = 0; j < 8; j++){
				int candx = curx + xx[j];
				int candy = cury + yy[j];
				if(candx >= 0 && candx < length && candy >= 0 && candy < length
						&& (arr[candx][candy] == 0 || arr[candx][candy] > cnt + 1)){
					arr[candx][candy] = cnt + 1;
					q.push(make_pair(make_pair(candx, candy), cnt + 1));
				}
			}
		}
	}
}
