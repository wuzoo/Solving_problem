#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[5001];
int ans = 10001;

bool check(int mid){
    int cnt = 0;

    int mn_val = 10001;
    int mx_val = 0;
    for(int i = 0; i < n; ++i){
        mn_val = min(arr[i], mn_val);
        mx_val = max(arr[i], mx_val);

        if(mx_val - mn_val > mid){
            cnt++;

            mn_val = arr[i];
            mx_val = arr[i];
        }
    }
    cnt++;
    
    return cnt > m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    int mn_val = 10001;
    int mx_val = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];

        mn_val = min(mn_val, arr[i]);
        mx_val = max(mx_val, arr[i]);
    }

    int st = 0;
    int en = mx_val;

    while(st < en){
        int mid = (st + en) / 2;

        if(check(mid)){
            st = mid + 1;
        }else{
            ans = min(ans, mid);
            en = mid;
        }
    }

    cout << ans;
}