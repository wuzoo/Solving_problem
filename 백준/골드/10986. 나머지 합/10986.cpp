#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int arr[1000001];
ll sum[1000001];
int result[1000001];
ll cnt[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; ++i){
        sum[i] = sum[i - 1] + arr[i];
        result[i] = sum[i] % m;
    }
    
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        if(result[i] == 0){
            ans++;
            ans += cnt[result[i]];
            cnt[result[i]]++;
        }else{
            ans += cnt[result[i]];
            cnt[result[i]]++;
        }
    }

    cout << ans;
}