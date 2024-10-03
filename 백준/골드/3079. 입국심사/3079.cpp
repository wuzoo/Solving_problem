#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long arr[100001];
long long ans;

bool check(long long mid) {
    long long cnt = 0;
    for(int i = 0; i < n; ++i){
        cnt += mid  / arr[i];

        if(cnt > m){
            break;
        }
    }
    if(cnt >= m) return true;
    
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m;

    long long max_time = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        max_time = max(max_time, arr[i]);
    }
    
    sort(arr, arr + n);

    long long st = 0;
    long long en = max_time * m;
    while(st < en){
        long long mid = (st + en) / 2;

        if(check(mid)){
            en = mid;
        }else{
            st = mid + 1;
        }
    }
    
    cout << st;
}