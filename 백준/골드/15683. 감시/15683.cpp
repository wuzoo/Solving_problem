#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[9][9];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int ans = 70;

vector<pair<int, pair<int, int>>> cctv;

void check(int x, int y, int dir){
    dir %= 4;
    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        x = nx;
        y = ny;

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) return;
        if(graph[nx][ny] == 6) return;
        if(graph[nx][ny] == 0){
            graph[nx][ny] = -1;
        }
    }
}

void dfs(int k){
    if(k == cctv.size()){
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(graph[i][j] == 0){
                    cnt++;
                }
            }
        }

        ans = min(ans, cnt);
        return;
    }
    int x = cctv[k].second.first;
    int y = cctv[k].second.second;

    int tmp[9][9];

    for(int dir = 0; dir < 4; dir++){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                tmp[i][j] = graph[i][j];
            }
        }

        if(graph[x][y] == 1){
            check(x, y, dir);
        }
        if(graph[x][y] == 2){
            check(x, y, dir);
            check(x, y, dir + 2);
        }
        if(graph[x][y] == 3){
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        if(graph[x][y] == 4){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
        }
        if(graph[x][y] == 5){
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        dfs(k + 1);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                graph[i][j] = tmp[i][j];
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

            if(graph[i][j] != 0 && graph[i][j] != 6){
                cctv.push_back({graph[i][j], {i, j}});
            }
        }
    }

    dfs(0);

    cout << ans;
}