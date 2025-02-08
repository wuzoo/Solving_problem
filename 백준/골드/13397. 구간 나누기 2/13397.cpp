#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[5001];
int ans;

bool check(int mid){
    int cnt = 0;

    int mx = 0;
    int mn = 10001;
    for(int i = 0; i < n; ++i){
        if(mx < arr[i]){
            mx = arr[i];
        }
        if(mn > arr[i]){
            mn = arr[i];
        }

        if(mx - mn > mid){
            cnt++;

            mx = arr[i];
            mn = arr[i];
        }
    }
    cnt++;

    return cnt > m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    int mx_val = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        mx_val = max(mx_val, arr[i]);
    }

    int st = 0;
    int en = mx_val;
    while(st <= en){
        int mid = (st + en) / 2;
        if(check(mid)){
            st = mid + 1;
        }else{
            ans = mid;
            en = mid - 1;
        }
    }

    cout << ans;
}