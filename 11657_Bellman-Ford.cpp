#include <bits/stdc++.h>
using namespace std;

#define INF 999999

vector<pair<int,pair<int,int>>>city;
long long dist[510];
int n, m;
bool cycle;

void bellman ()
{
    fill_n(dist, n+1, INF);
    
    for ( int i = 1 ; i <= n-1 ; i++ )
    {
        for ( int j = 0 ; j < city.size() ; j++ )
        {
            int from = city[j].first;
            int to = city[j].second.first;
            int weight = city[j].second.second;

            if ( dist[from] == INF ) continue;
			
			if( dist[to] > dist[from] + weight )
				dist[to] = dist[from] + weight; 
        }
    }

    for ( int j = 0 ; j < city.size() ; j++ )
        {
            int from = city[j].first;
            int to = city[j].second.first;
            int weight = city[j].second.second;

            if ( dist[from] == INF ) continue;
			
			if (dist[to] > dist[from] + weight)
            {
                cout << -1 << "\n";
                return;
            }
        }
    
    for (int i = 2; i <= n; i++)
    {
        if (dist[i] == INF) 
            cout << -1 << "\n";
        else 
            cout << dist[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int start, end, weight;
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++ )
    {
        cin >> start >> end >> weight;
        
        city.push_back({start,{end,weight}});
    }

    bellman();

    return 0;
}