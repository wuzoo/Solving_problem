#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; ++i){
            int a, b;
            cin >> a >> b;

            arr.push_back({a, b});
        }        

        sort(arr.begin(), arr.end());

        int cnt = 1;

        int m = arr[0].second;
        for(int i = 1; i < n; ++i){
            if(m > arr[i].second){
                cnt++;
            }
            m = min(m, arr[i].second);
        }

        cout << cnt << '\n';
    }
}