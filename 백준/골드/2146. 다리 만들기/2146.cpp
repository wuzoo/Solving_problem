#include <bits/stdc++.h>

using namespace std;

int n;
int graph[102][102];
int visited[102][102];
int areaNum[102][102];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans = 201;

void check(int cx, int cy, int num){
    queue<pair<int, int>> q;
    q.push({cx, cy});
    visited[cx][cy] = 1;
    areaNum[cx][cy] = num;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;
            
            if(graph[nx][ny] == 1){
                areaNum[nx][ny] = num;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

void bfs(int x, int y, int num){
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x, y}});
    visited[x][y] = 1;
    while(!q.empty()){
        int curx = q.front().second.first;
        int cury = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;
            if(areaNum[nx][ny] == num) continue;

            if(graph[nx][ny] == 1){
                ans = min(ans, cnt);
                return;
            }
            if(graph[nx][ny] == 0){
                visited[nx][ny] = 1;
                q.push({cnt + 1, {nx, ny}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
        }
    }

    int numbering = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(graph[i][j] == 1 && !visited[i][j]){
                check(i, j, numbering);
                numbering++;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    int cnt = 1;
    while(cnt <= numbering){
        vector<pair<int, int>> st;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(areaNum[i][j] == cnt){
                    st.push_back({i, j});
                }
            }
        }
        for(auto s: st){
            bfs(s.first, s.second, cnt);
            memset(visited, 0, sizeof(visited));
        }
        cnt++;
    }

    cout << ans;
}   