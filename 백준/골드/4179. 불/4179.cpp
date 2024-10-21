#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int visited[1001][1001][2];
int graph[1001][1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int r, c;
    cin >> r >> c;

    queue<pair<int, int>> fire_q;
    queue<pair<int, int>> jihoon_q;

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            char c;
            cin >> c;
            graph[i][j] = c;

            if(c == 'F'){
                fire_q.push({i, j});
                visited[i][j][0] = 1; // 불이 0
            }
            else if(c == 'J'){
                jihoon_q.push({i, j});
                visited[i][j][1] = 1; // 지훈이 1
            }
        }
    }

    while(!fire_q.empty()){
        int x = fire_q.front().first;
        int y = fire_q.front().second;
        fire_q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(visited[nx][ny][0]) continue;
            if(graph[nx][ny] == '#') continue;
            visited[nx][ny][0] = visited[x][y][0] + 1;
        
            fire_q.push({nx, ny});
        }
    }

    int ans = 0;

    while(!jihoon_q.empty()){
        int x = jihoon_q.front().first;
        int y = jihoon_q.front().second;
        jihoon_q.pop();

        if(x == 0 || x == r - 1 || y == 0 || y == c - 1){
            ans = visited[x][y][1];
            break;
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(visited[nx][ny][1]) continue;
            if(visited[x][y][1] + 1 >= visited[nx][ny][0] && visited[nx][ny][0]) continue;
            if(graph[nx][ny] == '#') continue;

            visited[nx][ny][1] = visited[x][y][1] + 1;
            jihoon_q.push({nx, ny});
        }
    }

    if(ans) cout << ans;
    else cout << "IMPOSSIBLE";
}