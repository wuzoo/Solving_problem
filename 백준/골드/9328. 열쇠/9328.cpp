#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int h, w;
char graph[111][111];
int visited[111][111];
int ans;
bool key[26]; // 0 ~ 25(A ~ Z)의 열쇠 개수

void bfs(int x, int y){
    queue<pair<int, int>> q;
    queue<pair<int, int>> later[26]; // 아직 열쇠가 없지만 추후에 다시 돌아와서 탐색 가능한 위치
    q.push({x, y});
    visited[x][y] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue;
            if(visited[nx][ny]) continue;
            if(graph[nx][ny] == '*') continue;

            visited[nx][ny] = 1;

            if(graph[nx][ny] >= 'A' && graph[nx][ny] <= 'Z'){
                if(key[graph[nx][ny] - 'A']){
                    q.push({nx, ny});
                }else{
                    later[graph[nx][ny] - 'A'].push({nx, ny});
                }
            }
            else if(graph[nx][ny] >= 'a' && graph[nx][ny] <= 'z'){
                q.push({nx, ny});
                key[graph[nx][ny] - 'a'] = true;

                while(!later[graph[nx][ny] - 'a'].empty()){
                    q.push(later[graph[nx][ny] - 'a'].front());
                    later[graph[nx][ny] - 'a'].pop();
                }
            }
            else{
                q.push({nx, ny});
                if(graph[nx][ny] == '$'){
                    ans++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        cin >> h >> w;

        for(int i = 1; i <= h; ++i){
            for(int j = 1; j <= w; ++j){
                cin >> graph[i][j];
            }
        }
        // 안밖을 마음껏 드나들 수 있음. 나갔다 들어오며 열쇠를 획득하고, 그 열쇠는 재사용이 가능함.
        string keys;
        cin >> keys;

        if(keys != "0"){
            for(int i = 0; i < keys.length(); ++i){
                key[keys[i] - 'a'] = true;
            }
        }

        bfs(0, 0);

        memset(visited, 0, sizeof(visited));
        memset(key, false, sizeof(key));
        memset(graph, 0, sizeof(graph));

        cout << ans << '\n';

        ans = 0;
    }
}