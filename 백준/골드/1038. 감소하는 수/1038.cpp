#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000001];
vector<string> ans;

void dfs(int k, int prev, int digit){
    if(k == digit){
        string s = "";
        for(int i = 0; i < k; ++i){
            s += arr[i] + '0';
        }
        ans.push_back(s);
        return;
    }
    for(int i = 0; i <= 9; ++i){
        if(i >= prev) continue;

        arr[k] = i;
        dfs(k + 1, i, digit);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i = 1; i <= 10; ++i){
        dfs(0, 11, i);
    }
    
    if(ans.size() > n){
        cout << ans[n];
    }else if(ans.size() <= n){
        cout << -1;
    }
}