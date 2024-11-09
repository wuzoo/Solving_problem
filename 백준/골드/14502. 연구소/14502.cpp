#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int graph[9][9];
vector<pair<int, int>> v;
int visited[9][9];
int wallVisited[9][9];
int ans;

int bfs(){
    int cnt = 0;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < v.size(); ++i){
        q.push({v[i].first, v[i].second});
        visited[v[i].first][v[i].second] = 1;
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || graph[nx][ny] == 1) continue;

            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(visited[i][j] == 0 && graph[i][j] != 1) cnt++;
        }
    }

    return cnt;
}

void search(int k){
    if(k == 3){
        ans = max(ans, bfs());
        memset(visited, 0, sizeof(visited));
        return;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!wallVisited[i][j] && graph[i][j] == 0){
                graph[i][j] = 1;
                wallVisited[i][j] = 1;
                search(k + 1);
                graph[i][j] = 0;
                wallVisited[i][j] = 0;
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

            if(graph[i][j] == 2){
                v.push_back({i, j});
            }
        }
    }

    search(0);

    cout << ans;
}