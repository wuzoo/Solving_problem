#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int n, m, k;
int graph[1001][1001];
int visited[1001][1001][11];

struct cmp{
    bool operator()(pair<tuple<int, int, int>, pair<int, int>> a, pair<tuple<int, int, int>, pair<int, int>> b){
        return get<2>(b.first) < get<2>(a.first);
    }
};

void bfs(int x, int y){
    priority_queue<pair<tuple<int, int, int>, pair<int, int>>, vector<pair<tuple<int, int, int>, pair<int, int>>>, cmp> q;
    q.push({{x, y, 01}, {0, 0}});
    visited[x][y][0] = 1;
    while(!q.empty()){
        int x = get<0>(q.top().first);
        int y = get<1>(q.top().first);
        int cnt = get<2>(q.top().first);
        int isNoon = q.top().second.first;
        int wallBreak = q.top().second.second;
        q.pop();

        if(x == n && y == m){
            cout << cnt;
            return;
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            
            if(graph[nx][ny] == 1 && wallBreak + 1 <= k && !visited[nx][ny][wallBreak + 1]){
                if(isNoon == 0){
                    visited[nx][ny][wallBreak + 1] = 1;
                    q.push({{nx, ny, cnt + 1}, {1, wallBreak + 1}});
                }else{
                    visited[nx][ny][wallBreak + 1] = 1;
                    q.push({{nx, ny, cnt + 2}, {1, wallBreak + 1}});
                }
            }
            else if(graph[nx][ny] == 0 && !visited[nx][ny][wallBreak]){
                if(isNoon == 1){
                    visited[nx][ny][wallBreak] = 1;
                    q.push({{nx, ny, cnt + 1}, {0, wallBreak}});
                }
                else{
                    visited[nx][ny][wallBreak] = 1;
                    q.push({{nx, ny, cnt + 1}, {1, wallBreak}});
                }            
            }
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char c;
            cin >> c;

            graph[i][j] = c - '0';
        }
    }   

    bfs(1, 1);
}   