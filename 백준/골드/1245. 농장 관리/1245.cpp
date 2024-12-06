#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[701][71];
int visited[701][71];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1 , -1, -1 };

bool bfs(int xx, int yy){
    queue<pair<int, int>> q;
    q.push({xx, yy});
    visited[xx][yy] = 1;

    bool can = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 8; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(graph[nx][ny] > graph[x][y]) can = false;

            if(visited[nx][ny]) continue;
            if(graph[xx][yy] != graph[nx][ny]) continue;

            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    return can;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> graph[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j] && graph[i][j] != 0){
                bool flag = bfs(i, j);

                if(flag){
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
}