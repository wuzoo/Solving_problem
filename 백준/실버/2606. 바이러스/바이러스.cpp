#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101];
int visited[101];
int cnt = -1;

void dfs(int v){
    visited[v] = 1;
    cnt++;
    for(int i = 0; i < graph[v].size(); ++i){
        int vertex = graph[v][i];
        if(!visited[vertex]){
            dfs(vertex);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    cout << cnt;
}