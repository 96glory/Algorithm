#include <bits/stdc++.h>
using namespace std;

string scroll, bridge[2];
int bridgeLen, scrollLen, arr[2][100][20];

int dp(int row, int column, int index){
    if(index == scrollLen)  return 1;

    int & temp = arr[row][column][index];
    if(temp != -1) return temp;

    temp = 0;
    for(int i = column; i < bridgeLen; i++){
        if(bridge[row][i] == scroll[index]){
            temp += dp(!row, i + 1, index + 1);
        }
    }

    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> scroll >> bridge[0] >> bridge[1];
    scrollLen = scroll.length();
    bridgeLen = bridge[0].length();

    memset(arr, -1, sizeof(arr));
    cout << dp(0, 0, 0) + dp(1, 0, 0);
}
