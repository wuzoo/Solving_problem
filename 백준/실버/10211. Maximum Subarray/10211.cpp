#include <bits/stdc++.h>
#define INF 0x7fffffff

using namespace std;

int arr[1001];
int sum[1001];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t, n;
    cin >> t;
    
    while(t--){
        cin >> n;

        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }

        int mx = -INF;
        for(int i = 1; i <= n; ++i){
            for(int j = i; j <= n; ++j){
                int subArrSum = sum[j] - sum[i - 1];
                mx = max(mx, subArrSum);
            }
        }

        cout << mx << '\n';
    }
}