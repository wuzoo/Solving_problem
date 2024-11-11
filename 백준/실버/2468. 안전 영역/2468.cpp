#include <bits/stdc++.h>

using namespace std;

int n;
int graph[101][101];
int visited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y, int h){
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 0});
    visited[x][y]= 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;
            if(graph[nx][ny] <= h) continue;

            visited[nx][ny] = 1;
            q.push({{nx, ny}, cnt + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    int max_val = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];

            max_val = max(max_val, graph[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= max_val; ++i){
        int cnt = 0;
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                if(i < graph[j][k] && !visited[j][k]){
                    cnt++;
                    bfs(j, k, i);
                }
            }
        }
        ans = max(ans, cnt);
        memset(visited, 0, sizeof(visited));
    }

    cout << ans;
}