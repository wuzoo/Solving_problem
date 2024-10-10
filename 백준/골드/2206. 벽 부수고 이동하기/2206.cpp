#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int graph[1001][1001];
int visited[1001][1001][2];

long long bfs(int x, int y){
    queue<pair<pair<int, int>, pair<long long, int>>> q;
    q.push({{x, y}, {0, 0}});
    
    visited[x][y][1] = 1;
    visited[x][y][0] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        long long cnt = q.front().second.first;
        int destroy = q.front().second.second;
        q.pop();

        if(x == n - 1 && y == m - 1){
            return cnt;
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(graph[nx][ny] == 0 && !visited[nx][ny][destroy]){
                visited[nx][ny][destroy] = 1;
                q.push({{nx, ny}, {cnt + 1, destroy}});
            }
            if(graph[nx][ny] == 1 && destroy == 0 && !visited[nx][ny][1]){
                visited[nx][ny][1] = 1;
                q.push({{nx, ny}, {cnt + 1, 1}});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c;
            cin >> c;
            graph[i][j] = c - '0';
        }
    }

    long long distance = bfs(0, 0);

    if(distance == -1) cout << -1;
    else cout << distance + 1;

    return 0;
}