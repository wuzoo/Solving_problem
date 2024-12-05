#include <bits/stdc++.h>
#define INF 1000000001

using namespace std;

int m, n;
int arr[1000001];
int ans;

bool check(int len){
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[i] / len;

        if(sum >= m){
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> n;

    int mx_val = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];

        mx_val = max(mx_val, arr[i]);
    }

    int st = 1;
    int en = mx_val;
    
    while(st <= en){
        int mid = (st + en) / 2;

        if(check(mid)){
            ans = max(ans, mid);
            st = mid + 1; 
        }else{
            en = mid - 1;
        }
    }

    cout << ans;
}