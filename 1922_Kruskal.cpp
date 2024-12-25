#include <bits/stdc++.h>
using namespace std;

// x 노드에서 y 노드까지의 비용 cost를 벡터에 배열마다 저장할 계획
typedef struct {
    int cost;
    int x;
    int y;
}network;

// vector에서 sort할 때 쓸 함수
bool cmp(network p, network q){
    return p.cost < q.cost;
}

int getParent(int cycle_table[], int z)
{
    if ( cycle_table[z] == z )
        return z;
    return cycle_table[z] = getParent(cycle_table, cycle_table[z]);
}

void unionParent(int cycle_table[], int a, int b) {
	a = getParent(cycle_table, a);
	b = getParent(cycle_table, b);
	// 더 숫자가 작은 부모로 병합
	if(a < b) 
        cycle_table[b] = a;
	else 
        cycle_table[a] = b;
} 

bool find(int x, int y, int cycle_table[])
{
    int a, b;
    
    a = getParent(cycle_table, x);
    b = getParent(cycle_table, y);

    if ( a == b )
        return false;
    else
        return true;
}

int main()
{
    int n, m; // 문제에서 제시한 n, m
    int x, y, cost; // x -> y 까지의 비용 cost
    vector<network>v; 
    int cycle_table[1001]; // 각 노드의 부모 노드를 저장할 배열 -> 사이클이 생기는 지 확인할 수 있음
    int total=0; // 최소 사이클 비용을 저장할 변수

    cin >> n;
    cin >> m;

    // 각 노드의 부모를 자기 자신으로 초기화
    for ( int i = 1 ; i <= n ; i++ )
        cycle_table[i] = i;

    // 배열에 입력값 삽입
    for( int i = 0 ; i < m ; i++ )
    {
        cin >> x >> y >> cost;
        v.push_back({cost,x,y});
    }
    
    // 낮은 비용 순으로 정렬
    sort(v.begin(), v.end(), cmp);
    
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        if ( find(v[i].x, v[i].y, cycle_table) )
        {
            total += v[i].cost;
            unionParent(cycle_table, v[i].x, v[i].y);
        }
    }

    cout << total;
    return 0;
}