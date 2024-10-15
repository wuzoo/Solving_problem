#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int r, c;
char graph[21][21];
int visited[27];
int mx;

void dfs(int x, int y, int k){
    mx = max(mx, k);
    
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <= 0 || nx > r || ny <= 0 || ny > c) continue;
        
        char c = graph[nx][ny];
        if(visited[int(c - 65)]) continue;
        
        visited[int(c - 65)] = 1;
        dfs(nx, ny, k + 1);
        visited[int(c - 65)] = 0;
    }
}   

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> r >> c;
    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            char c;
            cin >> c;
            graph[i][j] = c;
        }
    } 

    visited[int(graph[1][1] - 65)] = 1;
    dfs(1, 1, 0);

    cout << mx + 1;
}   