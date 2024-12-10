#include <bits/stdc++.h>

using namespace std;

int m, n;
int graph[701][701];
int growth[2001];

void cal(){
    int idx = 0;

    for(int i = m - 1; i >= 0; --i){
        graph[i][0] += growth[idx++];
    }
    for(int i = 1; i < m; ++i){
        graph[0][i] += growth[idx++];
    }

    int pos = 1;
    while(pos < m){
        for(int i = pos; i < m; ++i){
            graph[i][pos] = max(graph[i - 1][pos - 1], max(graph[i][pos - 1], graph[i - 1][pos]));
        }
        for(int i = pos + 1; i < m; ++i){
            graph[pos][i] = max(graph[pos - 1][i - 1], max(graph[pos][i - 1], graph[pos - 1][i]));
        }

        pos++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> m >> n;

    for(int i = 0; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        int idx = 0;
        for(int i = 0; i < a; ++i){
            growth[idx++] += 0;
        }
        for(int i = 0; i < b; ++i){
            growth[idx++] += 1;
        }
        for(int i = 0; i < c; ++i){
            growth[idx++] += 2;
        }
    }

    cal();

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            cout << graph[i][j] + 1 << ' ';
        }
        cout << '\n';
    }
}