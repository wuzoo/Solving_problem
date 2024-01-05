#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool visited[1000][1000];
int map[1000][1000];
int step[1000][1000];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int stx, sty;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    memset(step, -1, sizeof(step));

    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> map[i][j];
            if(map[i][j] == 2){
                stx = i;
                sty = j;
            }
            if(map[i][j] == 0){
                step[i][j] = 0;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({stx, sty});
    visited[stx][sty] = true;
    step[stx][sty] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
            if(map[nx][ny] != 1) continue;

            step[nx][ny] = step[x][y] + 1;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << step[i][j] << ' ';
        }
        cout << '\n';
    }
}