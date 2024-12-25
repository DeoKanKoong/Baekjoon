#include <bits/stdc++.h>
using namespace std;

int room[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int dd[4] = {3, 2, 1, 0};
int cnt;
bool flag = 0;

void dfs(int x, int y, int direction) {
    if ( room[x][y] == 1 ) flag = 1;
    
    if ( flag != 1 ){ 
        if ( room[x][y] == 0 ) {
            room [x][y] = 2;
            cnt += 1;
        }
        

        int i, di, c=0;
        if ( direction == 0 ) i = 0, di = 1;
        else if ( direction == 1 ) i = 3, di = 0;
        else if ( direction == 2 ) i = 2, di = 3;
        else if ( direction == 3 ) i = 1, di = 2; 
            
        while ( c != 4 ) {
            if ( i >= 4 ) i=0;

            int xx = x+dx[i];
            int yy = y+dy[i];

            if ( room[xx][yy] == 0 ) dfs(xx, yy, dd[i]);
            i += 1;
            c += 1;
        }

        if ( c == 4 ) dfs(x+dx[di], y+dy[di], direction);
    }
    return;
}


int main() {
    int n, m, x, y, direction;

    cin >> n >> m;
    cin >> x >> y >> direction;

    for ( int i = 0 ; i < n ; i++ ) 
        for ( int j = 0 ; j < m ; j++ )
            cin >> room[i][j];

    dfs(x, y, direction);
    cout << cnt;
    return 0;
}