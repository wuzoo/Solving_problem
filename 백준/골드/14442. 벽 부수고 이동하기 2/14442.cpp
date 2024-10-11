#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m, k;
int board[1001][1001];
int visited[1001][1001][11];

long long bfs(int x, int y){
    queue<pair<pair<int, int>, pair<long long, int>>> q;
    q.push({{x, y}, {0, 0}});
    visited[x][y][0] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        long long cnt = q.front().second.first;
        int wall_break = q.front().second.second;
        q.pop();

        if(x == n && y == m){
            return cnt;
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

            if(board[nx][ny] == 0 && !visited[nx][ny][wall_break]){
                visited[nx][ny][wall_break] = 1;
                q.push({{nx, ny}, {cnt + 1, wall_break}});
            }

            if(board[nx][ny] == 1 && wall_break < k && !visited[nx][ny][wall_break + 1]){
                visited[nx][ny][wall_break + 1] = 1;
                q.push({{nx, ny}, {cnt + 1, wall_break + 1}});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char c; cin >> c;
            board[i][j] = c - '0';
        }
    }

    long long cnt = bfs(1, 1);

    if(cnt == -1) cout << -1;
    else cout << cnt + 1;
}