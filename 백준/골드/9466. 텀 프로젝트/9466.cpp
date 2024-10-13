#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int visited[100001];
int done[100001];
int cnt;

void dfs(int v){
    int next = arr[v];
    visited[v] = 1;

    if(!visited[next]){
        dfs(next);
    }
    if(visited[next] && !done[next]){
        for(int i = next; i != v; i = arr[i]){
            cnt++;
        }
        cnt++;
    }
    done[v] = 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i = 1; i <= n; ++i){
            int v;
            cin >> v;
            arr[i] = v;
        }

        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                dfs(i);
            }
        }

        cout << n - cnt << '\n';

        cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(done, 0, sizeof(done));
    }
}