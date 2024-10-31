#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[9];
int ans[9];
int visited[9];
int cnt;

void dfs(int t){
    if(t == n){
        int current = 500;
        
        bool flag = false;
        for(int i = 0; i < n; ++i){
            current += (ans[i] - k);

            if(current < 500){
                flag = true;
                break;
            }
        }
        if(!flag){
            cnt++;
        }
        return;
    }
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            visited[i] = 1;
            ans[t] = arr[i];
            dfs(t + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    dfs(0);

    cout << cnt;
}