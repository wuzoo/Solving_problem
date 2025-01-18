#include <bits/stdc++.h>

using namespace std;

int r, c;
char graph[51][51];
int water[51][51];
int visited[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
pair<int, int> hole;

void bfs(int n, int w){
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {n, w}});
    visited[n][w] = 1;

    while(!q.empty()){
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(x == hole.first && y == hole.second){
            cout << cnt;
            return;
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(visited[nx][ny]) continue;
            if(graph[nx][ny] == 'X') continue;

            if(water[nx][ny] - 2 > cnt || !water[nx][ny]){
                q.push({cnt + 1, {nx, ny}});
                visited[nx][ny] = 1;
            }
        }
    }
    cout << "KAKTUS";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> r >> c;

    pair<int, int> start;
    queue<pair<int, int>> waterExist;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cin >> graph[i][j];

            if(graph[i][j] == '*'){
                waterExist.push({i, j});
                water[i][j] = 1;
            }
            if(graph[i][j] == 'S') start = {i, j};
            if(graph[i][j] == 'D') hole = {i, j};
        }
    }

    water[hole.first][hole.second] = 10001;

    while(!waterExist.empty()){
        int x = waterExist.front().first;
        int y = waterExist.front().second;
        waterExist.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(water[nx][ny]) continue;
            if(graph[nx][ny] == 'D' || graph[nx][ny] == 'X') continue;
            
            waterExist.push({nx, ny});
            water[nx][ny] = water[x][y] + 1;
        }
    }

    bfs(start.first, start.second);
}