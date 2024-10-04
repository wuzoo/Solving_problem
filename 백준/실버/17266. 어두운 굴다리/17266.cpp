#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100001];
int ans;

bool check(int mid){
    if(arr[0] > mid || arr[m - 1] < n - mid) return false;  
    
    for(int i = 0; i < m - 1; ++i){
        if(arr[i + 1] - arr[i] > 2 * mid) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        cin >> arr[i];
    }

    int st = 0;
    int en = n;
    while(st <= en){
        int mid = (st + en) / 2;

        if(check(mid)){
            ans = mid;
            en = mid - 1;
        }else{
            st = mid + 1;
        }
    }

    cout << ans;
}