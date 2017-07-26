#include <iostream>
const int MAXN = 1010;
using namespace std;
int ans;
int n, m;
bool vis[MAXN][MAXN];
char grid[MAXN][MAXN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
void dfs(int x, int y)
{
    vis[x][y] = 1;
    
    for(int i = 0; i < 4; i++)
    {
        int X = x +dx[i], Y = y +dy[i];
        
        if(X < 0 || Y < 0 || X > n +1 || Y > m +1)
            continue;
        
        if(grid[X][Y] == '1'){
            ans++;
            cout << x <<" "<< y << endl;
        }
        
        else if(!vis[X][Y])
            dfs(X, Y);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> grid[i][j];
            
    for(int i = 0; i < MAXN; i++)
        grid[i][0] = grid[0][i] = grid[n +1][i] = grid[i][m +1] = '0';
    
    dfs(0, 0);
    
    cout << ans << '\n';
    return 0;
}