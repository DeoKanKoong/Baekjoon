#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int dist[n+1][m+1];
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= m; j++) dist[i][j] = tmp[j-1] - '0';
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};

    queue<pair<pair<int, int>, pair<int, int>>> next;
    next.push({{1, 1}, {0, 1}});  

    bool visited[n+1][m+1][2] = {false}; 
    visited[1][1][0] = true;

    while (!next.empty()) {
        int x = next.front().first.first;
        int y = next.front().first.second;
        int wallBreak = next.front().second.first;
        int cnt = next.front().second.second;
        next.pop();

        if (x == n && y == m) {
            cout << cnt;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x < 1 || next_x > n || next_y < 1 || next_y > m) continue;

            if (dist[next_x][next_y] == 0 && !visited[next_x][next_y][wallBreak]) {
                visited[next_x][next_y][wallBreak] = true;
                next.push({{next_x, next_y}, {wallBreak, cnt + 1}});
            } else if (dist[next_x][next_y] == 1 && wallBreak == 0 && !visited[next_x][next_y][1]) {
                visited[next_x][next_y][1] = true;
                next.push({{next_x, next_y}, {1, cnt + 1}});
            }
        }
    }

    cout << "-1";
    return 0;
}
