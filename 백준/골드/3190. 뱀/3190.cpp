#include <bits/stdc++.h>

using namespace std;

int n, k;
int graph[101][101];
int visited[101][101];
int apple[101][101];
deque<pair<int, int>> pos;
queue<pair<int, char>> dir;

void bfs(int x, int y){
    queue<pair<pair<int, char>, pair<int, int>>> q;
    q.push({{0, 'R'}, {x, y}});
    pos.push_back({x, y});
    visited[x][y] = 1;

    while(!q.empty()){
        int time = q.front().first.first;
        char curDir = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        char nextDir = curDir;
        if(dir.front().first == time){
            if(dir.front().second == 'D'){
                if(curDir == 'T') nextDir = 'R';
                if(curDir == 'B') nextDir = 'L';
                if(curDir == 'L') nextDir = 'T';
                if(curDir == 'R') nextDir = 'B';
            }
            if(dir.front().second == 'L'){
                if(curDir == 'T') nextDir = 'L';
                if(curDir == 'B') nextDir = 'R';
                if(curDir == 'L') nextDir = 'B';
                if(curDir == 'R') nextDir = 'T';
            }
            dir.pop();
        }

        int nx, ny;
        if(nextDir == 'T'){
            nx = x - 1;
            ny = y;
        }
        if(nextDir == 'B'){
            nx = x + 1;
            ny = y;
        }
        if(nextDir == 'L'){
            nx = x;
            ny = y - 1;
        }
        if(nextDir == 'R'){
            nx = x;
            ny = y + 1;
        }

        if(nx <= 0 || ny <= 0 || nx > n || ny > n || visited[nx][ny]){
            cout << time + 1;
            break;
        }

        if(!apple[nx][ny]){ 
            pos.push_back({nx, ny});
            pair<int, int> tail = pos.front();
            visited[tail.first][tail.second] = 0;
            pos.pop_front();
        }else{
            pos.push_back({nx, ny});
            apple[nx][ny] = 0;
        }
        visited[nx][ny] = 1;
        q.push({{time + 1, nextDir}, {nx, ny}});
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    for(int i = 0; i < k; ++i){
        int x, y;
        cin >> x >> y;

        apple[x][y] = 1;
    }

    int l;
    cin >> l;
    
    for(int i = 0; i < l; ++i){
        int a; char c;
        cin >> a >> c;

        dir.push({a, c});
    }
   
    bfs(1, 1);
}