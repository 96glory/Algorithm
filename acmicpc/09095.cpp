#include <iostream>
 
using namespace std;
 
int cnt = 0;
 
void dfs(int acc,int target, int add)
{
    if (acc + add > target)
        return;
    if (acc + add == target)
        cnt++;
    dfs(acc + add, target, 1);
    dfs(acc + add, target, 2);
    dfs(acc + add, target, 3);
    return;
}
 
int main()
{
    ios::sync_with_stdio;
    cin.tie(0);
    
    int TC;
    cin >> TC;
    for (int tc = 0; tc < TC; tc++)
    {
        int N;
        cin >> N;
 
        dfs(0, N, 1);
        dfs(0, N, 2);
        dfs(0, N, 3);
 
        cout << cnt <<"\n";
        cnt = 0;
    }
    
    return 0;
}

