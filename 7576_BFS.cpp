#include <bits/stdc++.h>
using namespace std;

int dist[1001][1001];
int asdf[1001][1001];
queue<pair<int, pair<int,int> > >q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, maxx = -1;

void bfs()
{
    int x, y, nx, ny, cnt;
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second.first;
        cnt = q.front().second.second;
        q.pop();
        if ( cnt > maxx )
            maxx = cnt;

        for ( int i = 0 ; i < 4 ; i++ )
        {
            nx = x+dx[i];
            ny = y+dy[i];
            if ( asdf[nx][ny] == 0 )
            {
                if ( dist[nx][ny] == 1 )
                {
                    q.push({nx,{ny,cnt+1}});
                    asdf[nx][ny] = 1;
                    dist[nx][ny] = 2;
                }
            }
        }
    }
}


int main()
{
    int i, j, tmp;
    // 0 => 1 / 1 => 2

    cin >> n >> m;
    for ( i = 1 ; i <= m ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            cin >> tmp;
            if ( tmp == 0 )
                dist[i][j] = 1;
            else if ( tmp == 1 )
            {
                dist[i][j] = 2;
                q.push({i,{j,0}});
                asdf[i][j] = 1;
            }
            else
                dist[i][j] = -1;
        }
    }
    bfs();

    for ( int i = 1 ; i <= m; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( dist[i][j] == 1 )
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << maxx;
    return 0;
}