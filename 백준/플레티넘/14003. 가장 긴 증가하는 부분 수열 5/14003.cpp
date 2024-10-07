#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000001];
int result[1000001];
int dp[1000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    vector<int> v; 

    for(int i = 0; i < n; ++i){
        if(v.empty() || v.back() < arr[i]){
            v.push_back(arr[i]);
            result[i] = v.size() - 1;
        }else{
            int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();

            v[idx] = arr[i];
            result[i] = idx;
        }
    }

    vector<int> ans;
    int idx = v.size() - 1;
    for(int i = n - 1; i >= 0; --i){
        if(idx == result[i]){
            ans.push_back(arr[i]);
            --idx;
        }
    }

    cout << ans.size() << '\n';
    for(int i = ans.size() - 1; i >= 0; --i){
        cout << ans[i] << ' ';
    }
}