#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int map[500][500];
int visited[500][500];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int ret;

void shape(int i, int j)
{
	int sum = 0;
    if(i - 1 >= 0 && j + 2 < m){
        sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
	    ret = max(ret, sum);
    }   

    if(i + 1 < n && j + 2 < m){
        sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
	    ret = max(ret, sum);
    }

    if(i + 2 < n && j + 1 < m){
        sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
	    ret = max(ret, sum);
    }

    if(i - 1 >= 0 && i + 1 < n && j + 1 < m){
        sum = map[i][j] + map[i - 1][j + 1] + map[i][j + 1] + map[i + 1][j + 1];
	    ret = max(ret, sum);
    }
}

	

void dfs(int x, int y, int d, int s){
    if(d == 3){
        ret = max(ret, s);
        return;
    }
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        dfs(nx, ny, d + 1, s + map[nx][ny]);
        visited[nx][ny] = 0;
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            shape(i, j);
            visited[i][j] = 1;
            dfs(i, j, 0, map[i][j]);
            visited[i][j] = 0;
        }
    }
    cout << ret;
}