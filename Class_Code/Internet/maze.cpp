#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
    int x ,y;
    int depth;
};
const int n = 6, m = 8;
int mp[n + 3][m + 3] = { {0, 1, 0, 1, 0, 0, 0, 1},
                         {1, 0, 0, 1, 1, 0, 1, 0},
                         {0, 1, 1, 0, 0, 1, 1, 1},
                         {1, 0, 0, 1, 1, 0, 0, 1},
                         {1, 0, 0, 0, 1, 1, 0, 1},
                         {0, 1, 1, 1, 0, 0, 0, 0} };
bool vis[n + 3][m + 3];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int dfs()
{
    memset(vis, 0, sizeof(vis));
    queue <node> q;
    node temp = {0,0,0};
    q.push(temp);
    while(!q.empty()){
        node top = q.front();
        q.pop();
        if(top.x == n-1 && top.y == m-1){
            return top.depth;
        }
        
        for(int i = 0;i < 8;i++){
            int nx = top.x + dx[i];
            int ny = top.y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny]) continue;
            if(mp[nx][ny]) continue;

            vis[nx][ny] = 1;
            node temp1 = {nx,ny,top.depth+1};
            q.push(temp1);
            
        }
    }
    return -1;
}

int main()
{
    int ans = dfs();
    cout << ans << endl;

    return 0;
}