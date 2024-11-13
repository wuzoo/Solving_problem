#include <bits/stdc++.h>

using namespace std;

int n, r, l;
int graph[51][51];
int visited[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int sum;
vector<pair<vector<pair<int, int>>, int>> v;

void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    vector<pair<int, int>> tmp;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    tmp.push_back({sx, sy});
    sum += graph[sx][sy];

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;

            if(abs(graph[x][y] - graph[nx][ny]) >= l && abs(graph[x][y] - graph[nx][ny]) <= r){
                tmp.push_back({nx, ny});
                sum += graph[nx][ny];
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    v.push_back({tmp, sum});
    sum = 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> l >> r;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
        }
    }

    int move = 0;
    while(true){
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(!visited[i][j]){
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        if(v.size() == n * n){
            cout << move;
            break;
        }
        for(auto s: v){
            int aver = s.second / s.first.size();
            for(auto n: s.first){
                graph[n.first][n.second] = aver;
            }
        }
        move++;
        v.clear();
        memset(visited, 0, sizeof(visited));
    }
}