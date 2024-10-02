#include <bits/stdc++.h>

using namespace std;

char graph[1001][1001];
int firevisited[1001][1001];
int sangeunvisited[1001][1001];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans;

int n, m;

void BFS(queue<pair<int, int>> q){
    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(graph[nx][ny] == '#') continue;
            if(firevisited[nx][ny]) continue;

            firevisited[nx][ny] = firevisited[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        cin >> m >> n;

        pair<int, int> fireStart;
        pair<int, int> sangeunStart;

        queue<pair<int, int>> fire;
        queue<pair<int, int>> sangeun;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                char c;
                cin >> c;
                graph[i][j] = c;

                if(c == '@') sangeunStart = {i, j};
                if(c == '*'){
                    fire.push({i, j});
                    firevisited[i][j] = 1;
                }
            }
        }

        BFS(fire);

        bool canExit = false;

        sangeun.push({sangeunStart.first, sangeunStart.second});
        sangeunvisited[sangeunStart.first][sangeunStart.second] = 1;
        while(sangeun.size()){
            int x = sangeun.front().first;
            int y = sangeun.front().second;
            sangeun.pop();

            if(x == n - 1 || y == m - 1 || x == 0 || y == 0){
                canExit = true;
                ans = sangeunvisited[x][y];
                break;
            }

            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(graph[nx][ny] == '#') continue;
                if(sangeunvisited[nx][ny]) continue;

                int nextStep = sangeunvisited[x][y] + 1;

                if(nextStep >= firevisited[nx][ny] && firevisited[nx][ny]) continue;

                sangeunvisited[nx][ny] = sangeunvisited[x][y] + 1;
                sangeun.push({nx,ny});
            }
        }

        if(canExit){
            cout << ans;
        }else{
            cout << "IMPOSSIBLE";
        }
        cout << '\n';

        memset(sangeunvisited, 0, sizeof(sangeunvisited));
        memset(firevisited, 0, sizeof(firevisited));
    }
}