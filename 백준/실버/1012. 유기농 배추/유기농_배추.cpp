#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int visited[51][51];
int map[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m, k;

void dfs(int x, int y){
    visited[x][y] = 1;    
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(visited[nx][ny]) continue;
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 0) continue;
        dfs(nx, ny);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n >> k; // m : 가로, n : 세로 => map[n][m]

        for(int i = 0; i < k; ++i){
            int x, y;
            cin >> x >> y;

            map[y][x] = 1;
        }

        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!visited[i][j] && map[i][j] == 1){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
        memset(visited, 0, sizeof(visited));
        memset(map, 0, sizeof(map));
    }
}