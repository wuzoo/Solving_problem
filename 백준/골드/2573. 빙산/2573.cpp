#include <bits/stdc++.h>

using namespace std;
int n, m;
int graph[301][301];
int visited[301][301];
int result[301][301];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny]) continue;

            if(graph[nx][ny] == 0){
                result[x][y]++;
                continue;
            }

            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(graph[i][j] - result[i][j] >= 0){
                graph[i][j] -= result[i][j];
            }else{
                graph[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> graph[i][j];
        }
    }

    int time = 0;
    while(true){
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!visited[i][j] && graph[i][j] != 0){
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        if(cnt >= 2){
            cout << time << '\n';
            break;
        }
        if(cnt == 0){
            cout << 0 << '\n';
            break;
        }
        memset(visited, 0, sizeof(visited));
        memset(result, 0, sizeof(result));
        time++;
    }
}