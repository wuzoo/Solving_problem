#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[100][100][100];
int visited[100][100][100];
long long step[100][100][100];
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int zerosum = 0;
queue<pair<int, pair<int, int>>> q;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, n, h;
    cin >> m >> n >> h;

    memset(step, -1, sizeof(step));

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < m; ++k){
                cin >> map[j][k][i];
                if(map[j][k][i] == 1){
                    q.push({i, {j, k}});
                    visited[j][k][i] = 1;
                    step[j][k][i] = 0;
                }
                if(map[j][k][i] == 0){
                    zerosum++;
                }
            }
        }
    }
    if(zerosum == 0 && q.size() != 0){
        cout << 0;
    }
    else if(q.size() == 0){
        cout << -1;
    }
    else{
        while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int z = q.front().first;
        q.pop();

        for(int i = 0; i < 6; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h || visited[nx][ny][nz]) continue;
            if(map[nx][ny][nz] != 0) continue;
            visited[nx][ny][nz] = 1;
            q.push({nz, {nx, ny}});
            step[nx][ny][nz] = step[x][y][z] + 1;
            }
        }

        bool can = true;
        long long mx = 0;
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < m; ++k){
                    if(mx < step[j][k][i]){
                        mx = step[j][k][i];
                    }
                    else if(step[j][k][i] == -1 && map[j][k][i] == 0){
                        can = false;
                        break;
                    }
                }
            }
        }
        if(can) cout << mx;
        else cout << -1;
    }
}