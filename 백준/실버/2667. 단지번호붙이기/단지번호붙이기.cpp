#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int visited[26][26];
int map[26][26];
int n;
int cnt;
vector<int> cnts;

void dfs(int x, int y){
    visited[x][y] = 1;
    cnt++;
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(visited[nx][ny]) continue;
        if(nx < 1 || nx > n || ny > n || ny < 1 || map[nx][ny] != 1) continue;
        dfs(nx, ny);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            char c;
            cin >> c;
            map[i][j] = (c == '1');
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(!visited[i][j] && map[i][j] == 1){
                dfs(i, j);
                cnts.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << cnts.size() << '\n';
    sort(cnts.begin(), cnts.end());
    for(int i = 0; i < cnts.size(); ++i){
        cout << cnts[i] << '\n';
    }
}