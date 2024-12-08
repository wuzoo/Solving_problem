#include <bits/stdc++.h>

using namespace std;
int graph[51][51];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            char c;
            cin >> c;

            if(c == 'Y'){
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i == j) continue;

                if(graph[i][k] && graph[k][j]){
                    if(graph[i][j]){
                        graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
                    }else{
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int tmp = 0;
        for(int j = 1; j <= n; ++j){
            if(graph[i][j] == 1 || graph[i][j] == 2){
                tmp++;
            }
        }
        ans = max(ans, tmp);
    }

    cout << ans;
}