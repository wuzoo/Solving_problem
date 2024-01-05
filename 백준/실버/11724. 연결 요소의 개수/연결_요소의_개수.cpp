#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int v){
    visited[v] = true;
    for(int i = 0; i < graph[v].size(); ++i){
        int nv = graph[v][i];
        if(!visited[nv]){
            dfs(nv);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
}