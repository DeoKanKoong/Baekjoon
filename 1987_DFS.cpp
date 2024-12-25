#include <bits/stdc++.h>
using namespace std;

int R, C;
char board[21][21];
bool visited[26] = {false}; 
int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1};
int answer = 0;

void dfs(int x, int y, int count) {
    answer = max(answer, count);

    for (int i = 0; i < 4; i++) { 
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < R && ny < C && !visited[board[nx][ny] - 'A']) {
            visited[board[nx][ny] - 'A'] = true; 
            dfs(nx, ny, count + 1); 
            visited[board[nx][ny] - 'A'] = false; 
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1); 

    cout << answer; 
    return 0;
}
