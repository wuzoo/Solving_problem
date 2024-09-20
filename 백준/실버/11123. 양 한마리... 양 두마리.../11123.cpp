#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
char graph[101][101];
int visited[101][101];

void DFS(int, int);
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    
    while(T--){
        cin >> n >> m;    

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                char c;
                cin >> c;
                graph[i][j] = c;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!visited[i][j] && graph[i][j] == '#'){
                    visited[i][j] = 1;
                    cnt++;
                    DFS(i, j);
                }
            }
        }

        cout << cnt << '\n';

        memset(graph, '.', sizeof(graph));
        memset(visited, 0, sizeof(visited));
    }
}
void DFS(int x, int y){
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] == '.') continue;
        if(visited[nx][ny]) continue;

        visited[nx][ny] = 1;
        DFS(nx, ny);
    }
}