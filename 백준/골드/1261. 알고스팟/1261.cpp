#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int graph[101][101];
int visited[101][101];

void bfs(int x, int y){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, {x, y}});
    visited[x][y] = 1;
    while(!q.empty()){
        int x = q.top().second.first;
        int y = q.top().second.second;
        int cnt = q.top().first;
        q.pop();

        if(x == m - 1 && y == n - 1){
            cout << cnt;
            return;
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;
            
            visited[nx][ny] = 1;
            if(graph[nx][ny] == 1){
                q.push({cnt + 1, {nx, ny}});
            }else{
                q.push({cnt, {nx, ny}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            char c;
            cin >> c;

            graph[i][j] = c - '0';
        }
    }

    bfs(0, 0);
}