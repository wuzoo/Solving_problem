#include <bits/stdc++.h>
#define INF 500001

using namespace std;

int arr[100001];
int result_index[100001];
int dp[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    
    vector<pair<int, int>> arr;    
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;

        arr.push_back({a, b});
    }
    
    sort(arr.begin(), arr.end());
    
    vector<int> v;
    for(int i = 0; i < arr.size(); ++i){
        if(v.empty() || v.back() < arr[i].second){
            v.push_back(arr[i].second);
            result_index[i] = v.size() - 1;
        }else{
            int idx = lower_bound(v.begin(), v.end(), arr[i].second) - v.begin();

            v[idx] = arr[i].second;
            result_index[i] = idx;
        }
    }

    vector<int> ans;
    int idx = v.size() - 1;

    for(int i = arr.size() - 1; i >= 0; --i){
        if(result_index[i] == idx){
            ans.push_back(arr[i].first);
            idx--;
        }
    }

    vector<int> result;

    for(int i = 0; i < arr.size(); ++i){
        if(find(ans.begin(), ans.end(), arr[i].first) == ans.end()){
            result.push_back(arr[i].first);
        }
    }

    cout << result.size() << '\n';
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << '\n';
    }
}