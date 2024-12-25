#include <bits/stdc++.h>
using namespace std;

#define INF 999999

int dx[4] = {1, -1, 0 ,0};
int dy[4] = {0, 0, 1, -1};
int cave[126][126];
int dist[126][126];
int cave_size;

int dijkstra ()
{
    priority_queue <pair<int, pair<int, int>>> pq;
	pq.push(make_pair(-1 * cave[1][1], make_pair(1, 1)));
	dist[1][1] = cave[1][1];

	while (!pq.empty()) 
    {
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) 
        {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int ncost = cave[ny][nx];

			if (ny >= 1 && ny <= cave_size && nx >= 1 && nx <= cave_size) 
            {
				int before_v = dist[ny][nx];
				int current_v = dist[y][x] + ncost;
				if (before_v > current_v) 
                {
					dist[ny][nx] = current_v;
					pq.push(make_pair(-1 * current_v, make_pair(ny, nx)));
				}
			}
		}
	}
    return dist[cave_size][cave_size];  
}

int main()
{
    int cnt=0;
    while(1)
    {
        cin >> cave_size;
        if ( cave_size == 0 ) break;

        for ( int i = 1 ; i <= cave_size ; i++ )
            for ( int j = 1 ; j <= cave_size ; j++ )
            {
                cin >> cave[i][j];
                dist[i][j] = INF;
            }
                
     
        int result = dijkstra();
        cout << "Problem " << ++cnt << ": " << result << "\n";

    }
    return 0;
}