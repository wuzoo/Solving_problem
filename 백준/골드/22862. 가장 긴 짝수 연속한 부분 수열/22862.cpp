#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
int ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int ktry = 0;
    int en = 0;
    int st = 0;
    while(st < n && en < n){
        while(st <= en && ktry <= k){
            if(arr[en] % 2 != 0){
                ktry++;
            }
            en++;

            if(en == n) break;
        }

        ans = max(ans, en - st - ktry);

        while(ktry > k){
            if(arr[st] % 2 != 0){
                ktry--;
            }
            st++;
        }
    }

    cout << ans;
}