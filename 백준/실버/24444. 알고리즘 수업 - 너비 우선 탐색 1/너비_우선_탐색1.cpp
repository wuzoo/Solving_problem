#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100001];
int visited[100001];
int result[100001];
int cnt;

int main(){
    int n, m, r;
    cin >> n >> m >> r;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i){
        sort(graph[i].begin(), graph[i].end());       
    }

    queue<int> q;
    q.push(r);
    visited[r] = 1;
    cnt++;
    result[r] = cnt;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < graph[x].size(); ++i){
            int v = graph[x][i];
            if(!visited[v]){
                visited[v] = 1;
                cnt++;
                result[v] = cnt;
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << result[i] << '\n';
    }
}