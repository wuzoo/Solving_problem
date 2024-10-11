#include <bits/stdc++.h>

using namespace std;

int n;
int arr[4001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;   

    int max_val = 0;
    set<int> s;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        max_val = max(max_val, arr[i]);
        s.insert(arr[i]);
    }

    set<int> gap;
    vector<int> ans;

    for(int i = 1; i < n; ++i){
        gap.insert(arr[i] - arr[0]);
    }

    for(auto e : gap){
        set<int> idx;
        for(int i = 0; i < n; ++i){
            if(s.find(arr[i]) != s.end() && s.find(arr[i] + e) != s.end()){
                idx.insert(arr[i]);
                idx.insert(arr[i] + e);
            }
        }

        if(idx.size() == n) ans.push_back(e);
    }

    cout << ans.size() << '\n';

    sort(ans.begin(), ans.end());

    for(auto e : ans) cout << e << ' ';
}