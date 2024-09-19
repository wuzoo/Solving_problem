#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
char map[51][51];
int visited[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans;

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    
    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N || map[nx][ny] == 'W') continue;

            if(visited[nx][ny]) continue;

            visited[nx][ny] = visited[x][y] +  1;
            q.push({nx, ny});

            if(ans < visited[nx][ny]){
                ans = visited[nx][ny];
            }

            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;;

    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }

    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            if(map[i][j] == 'L'){
                BFS(i, j);
                memset(visited, 0, sizeof(visited));
            }
        }
    }

    cout << ans - 1;
}