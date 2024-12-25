#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

vector<pair<int,int>>node[10001]; 
queue<int>rtn;
int dist[10001];

int dijkstra(int start, int target, int n)
{
    fill_n(dist, n + 1, INF);
    priority_queue<pair<int,int>>pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) 
    {
        int curDist = -pq.top().first; 
        int curNum = pq.top().second; 
        pq.pop();

        if (curDist > dist[curNum]) continue;

        for(auto edge: node[curNum]) 
        {
        	int adjNum = edge.first; 
            int cost = edge.second; 
            int newCost = curDist + cost; 
            

            if(dist[adjNum] > newCost){
            	dist[adjNum] = newCost;
                pq.push({-newCost, adjNum});
            }
        }
    }   
    if ( start == target )
    {
        for ( int i = 1 ; i <= n ; i++ )
            if ( dist[i] != 0 )
                rtn.push(dist[i]);    
    }
    return dist[target];
}

int main()
{
    int n, num, target, m, weight;

    cin >> n >> num >> target;

    for ( int i = 0 ; i < num ; i++ )
    {
        int x, y;
        cin >> x >> y >> weight; 
        node[x].push_back({y, weight});
    }

    int max = -99999999;
    dijkstra(target, target, n);
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( i == target )
            continue;
        else 
        {
            int result = dijkstra(i, target, n)+rtn.front();
            if ( max < result )
                max = result;
            rtn.pop();
        }
        
    }
    
    cout << max;
    return 0;
}