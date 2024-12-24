#include <bits/stdc++.h>

using namespace std;

int n, k; 
int visited;
string arr[51];
int ans;

void dfs(int t, int idx){
    if(t == k - 5){
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            bool flag = true;
            for(int j = 4; j < arr[i].length() - 4; ++j){
                if(!(visited & (1 << (arr[i][j] - 97)))){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }
    for(int i = idx; i < 27; ++i){
        if(!(visited & (1 << i))){
            visited |= (1 << i);
            dfs(t + 1, i);
            visited &= ~(1 << i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    if(k < 5){
        cout << 0;
        return 0;
    }
    
    char origin[5] = {'a', 'n', 'i', 'c', 't'};
    for(auto s: origin){
        visited |= (1 << (s - 97));
    }

    dfs(0, 0);

    cout << ans;
}