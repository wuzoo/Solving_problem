#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int N, M;                       
int map[MAX][MAX];             
int visited[MAX][MAX];          
int check[MAX][MAX];             
int dx[4] = {0, 0, -1, 1};   
int dy[4] = {1, -1, 0, 0};   
queue<pair<int,int> > q;        

void bfs(int x, int y){         

    visited[x][y] = 1;          
    q.push(make_pair(x,y));     

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0; i<4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(visited[nx][ny]) continue;
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 0) continue;

            visited[nx][ny] = 1;              
            q.push(make_pair(nx, ny));        
            check[nx][ny] = check[x][y] + 1;    
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;                      

    for (int i = 0; i < N; ++i){            
        string row;                     
        cin >> row;

        for (int j = 0; j < M; ++j){        
            map[i][j] = row[j]-'0';    
        }
    }

    bfs(0, 0);                          
    cout << check[N - 1][M - 1] + 1;             
}