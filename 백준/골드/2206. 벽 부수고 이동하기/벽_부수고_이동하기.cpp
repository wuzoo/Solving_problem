#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int visited[1001][1001][2]; // [0]: 벽 안부수고, [1]: 벽 부수고
int map[1001][1001];
long long step[1001][1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        string s;
        cin >> s;

        for(int j = 0; j < m; ++j){
            map[i][j + 1] = s[j] - '0';
        }
    }

    // 한 개의 벽만 부수는 게 가능.
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {1, 1}});
    visited[1][1][0] = 1;
    visited[1][1][1] = 1;
    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        if(x == n && y == m){
            cout << step[n][m] + 1;
            return 0;
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

            if(map[nx][ny] == 1 && cnt == 0 && !visited[nx][ny][cnt + 1]){
                visited[nx][ny][cnt + 1] = 1;
                step[nx][ny]= step[x][y] + 1;
                q.push({cnt + 1, {nx, ny}});
            }
            if(map[nx][ny] == 0 && !visited[nx][ny][cnt]){
                visited[nx][ny][cnt] = 1;
                step[nx][ny]= step[x][y] + 1;
                q.push({cnt, {nx, ny}});
            }
        }
    }
    cout << -1;
}