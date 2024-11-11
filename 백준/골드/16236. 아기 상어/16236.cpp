#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n;
int graph[21][21];
int visited[21][21];
int shark_size = 2;
bool eat = false;
int result;
pair<int, int> pos;

void bfs(int x, int y){
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 0});
    visited[x][y] = 1;

    int tmp;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;

        if(graph[x][y] > 0 && graph[x][y] < shark_size && cnt == tmp){
            if(x < pos.first || (x == pos.first && y < pos.second)){
                pos = {x, y};
                continue;
            }
        }
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;

            if(graph[nx][ny] > shark_size) continue;

            if(graph[nx][ny] > 0 && graph[nx][ny] < shark_size && !eat){
                pos = {nx, ny};
                eat = true;
                tmp = cnt + 1;
                result += tmp;
            }else{
                visited[nx][ny] = 1;
                q.push({{nx, ny}, cnt + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];

            if(graph[i][j] == 9){
                pos = {i, j};
                graph[i][j] = 0;
            }
        }
    }

    bool stop = false;
    int cnt = 0;
    while(!stop){
        bfs(pos.first, pos.second);
        memset(visited, 0, sizeof(visited));

        if(eat){
            eat = false;
            graph[pos.first][pos.second] = 0;
            cnt++;

            if(cnt == shark_size){
                shark_size++;
                cnt = 0;
            }
        }else{
            stop = true;
        }
    }

    cout << result;
}