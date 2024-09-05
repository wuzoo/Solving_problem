#include <iostream>
using namespace std;

char map[101][101];
int visited[101][101];
int visited2[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n;

void dfs(int x, int y, char c){
    visited[x][y] = 1;

    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
        if(map[nx][ny] != c) continue;

        dfs(nx, ny, c);
    }
}

void dfs2(int x, int y, char c){
    visited2[x][y] = 1;

    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited2[nx][ny]) continue;
        
        if(c == 'B'){
            if(map[nx][ny] != 'B') continue;
        }
        else{
            if(map[nx][ny] == 'B') continue;
        }

        dfs2(nx, ny, c);
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> map[i][j];
        }
    }

    int cnt = 0; int cnt2 = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!visited[i][j]){
                char color = map[i][j];
                dfs(i, j, color);
                cnt++;
            }
            if(!visited2[i][j]){
                char color = map[i][j];
                dfs2(i, j, color);
                cnt2++;
            }
        }
    }
    cout << cnt << ' ' << cnt2;
}