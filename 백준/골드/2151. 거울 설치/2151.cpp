#include <bits/stdc++.h>
#define INF 987654321

using namespace std;
int n;
char graph[51][51];
int visited[51][51][4];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct Point{
    int x, y;
    int Dir; // 0 상|1 하|2 좌|3 우
};

pair<int, int> changed_dir(int dir){
    pair<int, int> tmp;
    if(dir == 0 || dir == 1){
        tmp = {2, 3};
    }else if(dir == 2 || dir == 3){
        tmp = {0, 1};
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    pair<int, int> st;
    pair<int, int> en;
    bool flag = false;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
            if(graph[i][j] == '#' && !flag){
                st = {i, j};
                flag = true;
            }else if(graph[i][j] == '#' && flag){
                en = {i, j};
            }
            visited[i][j][0] = visited[i][j][1] = visited[i][j][2] = visited[i][j][3] = INF;
        }
    }

    queue<Point> q;
    for(int i = 0; i < 4; ++i){
        Point tmp;
        tmp.x = st.first;
        tmp.y = st.second;
        tmp.Dir = i;
        q.push(tmp);
        visited[st.first][st.second][i] = 0;
    }

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().Dir; // 0 1 2 3
        q.pop();

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        pair<int, int> nd = changed_dir(dir);

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        if(graph[nx][ny] == '*') continue;

        if(graph[nx][ny] == '!'){
            if(visited[x][y][dir] < visited[nx][ny][dir]){
                visited[nx][ny][dir] = visited[x][y][dir];
                q.push({nx, ny, dir});
            }
            if(visited[x][y][dir] + 1 < visited[nx][ny][nd.first]){
                visited[nx][ny][nd.first] = visited[x][y][dir] + 1;
                q.push({nx, ny, nd.first});
            }
            if(visited[x][y][dir] + 1 < visited[nx][ny][nd.second]){
                visited[nx][ny][nd.second] = visited[x][y][dir] + 1;
                q.push({nx, ny, nd.second});
            }
        }

        if(graph[nx][ny] == '.'){
            if(visited[x][y][dir] < visited[nx][ny][dir]){
                visited[nx][ny][dir] = visited[x][y][dir];
                q.push({nx, ny, dir});
            }
        }

        if(graph[nx][ny] == '#'){
            if(visited[nx][ny][dir] > visited[x][y][dir]){
                visited[nx][ny][dir] = visited[x][y][dir];
            }
        }
    }

    int mn = INF;
    for(int i = 0; i < 4; ++i){
        mn = min(mn, visited[en.first][en.second][i]);
    }

    cout << mn;
}