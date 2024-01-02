#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int n, s;
int arr[100001];
int sum[100001];
int ans = MAX;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    int en = 1;
    for(int st = 1; st <= n; ++st){
        int tmp = sum[en] - sum[st - 1];
        while(tmp < s && en <= n){
            en++;
            if(en != n + 1) tmp += arr[en];
        }
        if(en == n + 1) break;
        ans = min(ans, en - st + 1);
    }
    if(ans == MAX) cout << 0;
    else cout << ans;
}