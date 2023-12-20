// 백준 11404번 (플로이드 워셜 알고리즘)
#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

int main()
{
    int n, m, x, y, cost;
    int dist[101][101];

    cin >> n >> m;

    for ( int i = 0 ; i < 101 ; i++ )
        for ( int j = 0 ; j < 101 ; j++ )
        {
            dist[i][j] = INF;
        }

    for ( int i = 0 ; i < m ; i++ )
    {
        cin >> x >> y >> cost;
        if ( dist[x][y] == INF || dist[x][y] > cost )
            dist[x][y] = cost;
    }
    
    for ( int k = 1 ; k <= n ; k++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            for ( int i = 1 ; i <= n ; i++ )
            {
                if ( i != j && i != k && j != k )
                {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( dist[i][j] == INF )
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    } 

    return 0;
}