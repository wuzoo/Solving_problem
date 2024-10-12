#include <bits/stdc++.h>

using namespace std;


int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m;
char board[11][11];
int visited[11][11][11][11]; // [rx][ry][bx][by]

int bfs(int x, int y, int bx, int by){ // 빨간공과 파란공을 동시에 움직여야함.
    queue<tuple<pair<int, int>, pair<int, int>, int>> q;
    q.push({{x, y}, {bx, by}, 0});
    visited[x][y][bx][by] = 1;

    while(!q.empty()){
        int rx = get<0>(q.front()).first;
        int ry = get<0>(q.front()).second;
        int bx = get<1>(q.front()).first;
        int by = get<1>(q.front()).second;
        int cnt = get<2>(q.front());
        q.pop();

        if(cnt + 1 > 10){
            return -1;
        };

        for(int i = 0; i < 4; ++i){
            int nrx = rx;
            int nry = ry;
            int nbx = bx;
            int nby = by;

            int rt = 0, bt = 0;

            while(board[nrx + dx[i]][nry + dy[i]] != '#' && board[nrx][nry] != 'O'){
                nrx += dx[i];
                nry += dy[i];
                rt++;
            }
            while(board[nbx + dx[i]][nby + dy[i]] != '#' && board[nbx][nby] != 'O'){
                nbx += dx[i];
                nby += dy[i];
                bt++;
            }

            if(board[nbx][nby] == 'O') continue; // 다른 루트 찾음
            if(board[nrx][nry] == 'O'){
                return cnt + 1;
            }
            

            if(nrx == nbx && nry == nby){
                if(rt > bt){
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else{
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if(visited[nrx][nry][nbx][nby]) continue;

            visited[nrx][nry][nbx][nby] = 1;
            q.push({{nrx, nry}, {nbx, nby}, cnt + 1});
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    pair<int, int> red, blue;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            board[i][j] = c;

            if(c == 'R'){
                red = {i, j};
            }
            else if(c == 'B'){
                blue = {i, j};
            }
        }
    }

    int cnt = bfs(red.first, red.second, blue.first, blue.second);

    cout << cnt;

    return 0;
}