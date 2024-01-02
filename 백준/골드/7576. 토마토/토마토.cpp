#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
int visited[1000][1000];
int map[1000][1000];
ll step[1000][1000];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;   
int zerosum;

int main(){
    cin >> m >> n;

    memset(step, -1, sizeof(step));
    vector<pair<int, int>> ones;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> map[i][j];
            if(map[i][j] == 1) ones.push_back({i, j});
            if(map[i][j] == 0) zerosum++;
        }
    }

    if(zerosum == 0 && ones.size() != 0){
        cout << 0;
    }
    else if(zerosum != 0 && ones.size() == 0){
        cout << -1;
    }
    else{
        queue<pair<int, int>> q;
        for(int i = 0; i < ones.size(); ++i){
            q.push(ones[i]);
            visited[ones[i].first][ones[i].second] = 1;
            step[ones[i].first][ones[i].second] = 0;
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] != 0) continue;
                if(visited[nx][ny]) continue;

                visited[nx][ny] = 1;
                step[nx][ny] = step[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }

        ll mx = 0;
        bool canMake = false;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(step[i][j] == -1 && map[i][j] == 0){
                    canMake = true;
                    break;
                }
                else if(mx < step[i][j]){
                    mx = step[i][j];
                }
            }
            if(canMake) break;
        }
        if(canMake) cout << -1;
        else cout << mx;
    }
}