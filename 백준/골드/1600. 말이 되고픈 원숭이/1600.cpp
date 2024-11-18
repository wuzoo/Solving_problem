#include <bits/stdc++.h>

using namespace std;

int w, h, k;
int graph[201][201];
int visited[201][201][31];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int djx[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int djy[8] = {2, 2, -2, -2, 1, 1, -1, -1};

void bfs(int x, int y){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{x, y}, {0, 0}});
    visited[x][y][0] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int jumpCnt = q.front().second.second;
        q.pop();

        if(x == h - 1 && y == w - 1){
            cout << cnt;
            return;
        }

        for(int i = 0; i < 8; ++i){
            int nx = x + djx[i];
            int ny = y + djy[i];
            int nCnt = jumpCnt + 1;

            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(visited[nx][ny][nCnt]) continue;
            if(graph[nx][ny] == 1) continue;
            if(nCnt > k) continue;

            visited[nx][ny][nCnt] = 1;
            q.push({{nx, ny}, {cnt + 1, nCnt}});
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(visited[nx][ny][jumpCnt]) continue;
            if(graph[nx][ny] == 1) continue;
            
            visited[nx][ny][jumpCnt] = 1;
            q.push({{nx, ny}, {cnt + 1, jumpCnt}});
        }
    }

    cout << -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> k;

    cin >> w >> h;

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cin >> graph[i][j];
        }
    }

    bfs(0, 0);
}