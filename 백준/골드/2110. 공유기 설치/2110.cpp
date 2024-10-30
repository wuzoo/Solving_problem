#include <bits/stdc++.h>

using namespace std;

int n, c;
long long ans;
long long arr[200001];

bool check(long long mid){
    int cnt = 1;
    int tmp = arr[0];
    for(int i = 1; i < n; ++i){
        if(arr[i] >= tmp + mid){
            cnt++;
            tmp = arr[i];
        }
    }

    if(cnt >= c){
        return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> c;

    long long max_val = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];

        max_val = max(max_val, arr[i]);
    }

    sort(arr, arr + n);

    long long st = 0;
    long long en = max_val;

    while(st <= en){
        long long mid = (st + en) / 2;

        if(check(mid)){
            ans = max(ans, mid);
            st = mid + 1;
        }else{
            en = mid - 1;
        }
    }

    cout << ans;
}