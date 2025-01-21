#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, k;
int graph[21][21];
int top, bottom, east, west, north, south;
int cur_x, cur_y;

void move(int command){
    switch(command){
        case 1:{ // 동쪽
            if(cur_x + 1 >= m) return;

            cur_x += 1;
            if(graph[cur_x][cur_y] == 0){
                int tmp[4] = {top, east, bottom, west};
                east = top; bottom = tmp[1]; west = tmp[2]; top = tmp[3];
                graph[cur_x][cur_y] = bottom;
            }else{
                int tmp[4] = {top, east, bottom, west};
                east = top; bottom = graph[cur_x][cur_y]; west = tmp[2]; top = tmp[3];
                graph[cur_x][cur_y] = 0;
            }
            
            break;
        }   
        case 2:{ // 서쪽
            if(cur_x - 1 < 0) return;

            cur_x -= 1;
            if(graph[cur_x][cur_y] == 0){
                int tmp[4] = {top, east, bottom, west};
                west = top; bottom = tmp[3]; east = tmp[2]; top = tmp[1];
                graph[cur_x][cur_y] = bottom;
            }else{
                int tmp[4] = {top, east, bottom, west};
                west = top; bottom = graph[cur_x][cur_y]; east = tmp[2]; top = tmp[1];
                graph[cur_x][cur_y] = 0;
            }

            break;
        }
        case 3:{ // 북쪽
            if(cur_y - 1 < 0) return;

            cur_y -= 1;
            if(graph[cur_x][cur_y] == 0){
                int tmp = top;
                top = south; south = bottom; bottom = north; north = tmp;
                graph[cur_x][cur_y] = bottom;
            }else{
                int tmp = top;
                top = south; south = bottom; bottom = graph[cur_x][cur_y]; north = tmp;
                graph[cur_x][cur_y] = 0;
            }
            
            break;
        }
        case 4:{ // 남쪽
            if(cur_y + 1 >= n) return;

            cur_y += 1;
            if(graph[cur_x][cur_y] == 0){
                int tmp = top;
                top = north; north = bottom; bottom = south; south = tmp;
                graph[cur_x][cur_y] = bottom;
            }else{
                int tmp = top;
                top = north; north = bottom; bottom = graph[cur_x][cur_y]; south = tmp;
                graph[cur_x][cur_y] = 0;
            }
            
            break;
        }
    }

    cout << top << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> graph[j][i];
        }
    }

    cur_x = y;
    cur_y = x;

    for(int i = 0; i < k; ++i){
        int input; cin >> input;

        move(input);
    }
}