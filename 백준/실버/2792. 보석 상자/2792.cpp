#include <bits/stdc++.h>
#define MAX 1000000000

using namespace std;

int ans = MAX;
int n, m;
int arr[300001];

bool check(int mid){
    int sum = 0;
    for(int i = 0; i < m; ++i){
        int total = arr[i];

        int d = 0;
        if(total % mid == 0){
            d = total / mid;
        }else{
            d = total / mid + 1;
        }

        sum += d;

        if(sum > n){
            break;
        }
    }

    if(sum > n) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        cin >> arr[i];
    }

    int st = 1;
    int en = MAX;
    while(st <= en){
        int mid = (st + en) / 2;

        if(check(mid)){
            en = mid - 1;
            ans = min(ans, mid);
        }else{
            st = mid + 1;
        }
    }

    cout << ans;
}