#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int visited[300][300];
int step[300][300];
int dx[8] = {1, -1, -2, -2, -1, 1, 2, 2};
int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int n;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        int curx, cury, destx, desty;
        cin >> curx >> cury;
        cin >> destx >> desty;

        queue<pair<int, int>> q;

        q.push(make_pair(curx, cury));
        visited[curx][cury] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == destx && y == desty){
                cout << step[x][y] << '\n';
                break;
            }

            for(int i = 0; i < 8; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if(visited[nx][ny]) continue;

                step[nx][ny] = step[x][y] + 1;
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
        memset(visited, 0, sizeof(visited));
        memset(step, 0, sizeof(step));
    }
    
    return 0;
}