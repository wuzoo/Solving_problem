#include <iostream>
#include <queue>
using namespace std;
int visited[101];
int step[101];
int map[101];
int dx[6] = {1, 2, 3, 4, 5, 6};
int n, m;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        int u, v;
        cin >> u >> v;
        map[u] = v;
    }
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        map[u] = v;
    }

    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == 100){
            cout << step[x];
            break;
        }
        else{
            for(int i = 0; i < 6; ++i){
                int nx = x + dx[i];

                if(nx < 1 || nx > 100) continue;

                if(map[nx] != 0){
                    nx = map[nx];
                }

                if(visited[nx]) continue;
                visited[nx] = 1;
                step[nx] = step[x] + 1;
                q.push(nx);
            }
        }
    }
}