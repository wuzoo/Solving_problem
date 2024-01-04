#include <iostream>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int visited[600][600];
char map[600][600];
int n, m;
int cnt;

void dfs(int x, int y){
    visited[x][y] = 1;
    if(map[x][y] == 'P') cnt++;

    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
        if(map[nx][ny] == 'X') continue;

        dfs(nx, ny);
    }
}

int main(){    
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(map[i][j] == 'I'){
                dfs(i, j);
            }
        }
    }

    if(cnt == 0) cout << "TT";
    else cout << cnt;
}