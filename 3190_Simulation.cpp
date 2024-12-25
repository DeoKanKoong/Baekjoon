#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n;
queue<pair<int,int> >snake;

void dummy ( int x, int y, int second, int dist[][101], queue<pair<int, int> >change, int direction, pair<int,int>tail  ) {  
    if ( ( x == 0 || x == n+1 ) || ( y == 0 || y == n+1 ) ) {
        cout << second;
        return;
    }

    dist[x][y] = 2;
    
    int dx[4] = {0, 0, -1, 1}; 
    int dy[4] = {1, -1, 0, 0};

    if ( !change.empty() && second == change.front().first ) {
        if ( change.front().second == 1 ) {
            if ( direction == 0 ) direction = 3;
            else if ( direction == 1 ) direction = 2;
            else if ( direction == 2 ) direction = 0;
            else if ( direction == 3 ) direction = 1;
        }
        else if ( change.front().second == 2 ) {
            if ( direction == 0 ) direction = 2;
            else if ( direction == 1 ) direction = 3;
            else if ( direction == 2 ) direction = 1;
            else if ( direction == 3 ) direction = 0;
        }
        change.pop();
    }

    int next_x = x + dx[direction];
    int next_y = y + dy[direction];

    snake.push({next_x,next_y});
    if ( dist[next_x][next_y] == 1 ) {
        dummy(next_x, next_y, second+1, dist, change, direction, tail);
    }
    else if ( dist[next_x][next_y] == 0 ) {
        dist[tail.first][tail.second] = 0;
        tail = snake.front();
        snake.pop();
        dummy(next_x, next_y, second+1, dist, change, direction, tail);
    }
    else if ( dist[next_x][next_y] == 2 ) {
        cout << second+1;
        return;
    }
       
}

int main() {
    cin >> n;
    int dist[101][101] = {0};
    queue<pair<int, int> >change;

    int m;
    cin >> m;
    for ( int i = 0 ; i < m ; i++ ) {
        int x, y;
        cin >> x >> y;
        dist[x][y] = 1;
    }

    cin >> m;
    for ( int i = 0 ; i < m ; i++ ) {
        int x;
        char d;
        cin >> x >> d;
        if ( d == 'D' ) change.push({x,1});
        else change.push({x,2});
    }
    dummy(1,1,0, dist, change, 0, make_pair(1,1)); 
    return 0;
}