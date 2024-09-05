#include <iostream>
#include <algorithm>
using namespace std;

int graph[101][101];
int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int start, end, cost;
        cin >> start >> end >> cost;

        if(graph[start][end]){
            graph[start][end] = min(cost, graph[start][end]);    
        }else{
            graph[start][end] = cost;
        }
    }

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(graph[i][k] && graph[k][j]){
                    if(i == j) continue;

                    if(graph[i][j] == 0){
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }else{
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(graph[i][j] == 0) cout << 0 << ' ';
            else cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
// 1 2 2
// 1 3 3
// 1 4 1
// 1 5 10
// 1 4 2