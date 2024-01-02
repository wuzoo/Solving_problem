#include <iostream>
#include <algorithm>
#define INF 10000000000
using namespace std;

int arr[100001];
int ans = INF;
int n,m;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int en = 0;
    for(int st = 0; st < n; ++st){
        while(arr[en] - arr[st] < m && en < n){
            en++;
        }
        if(en >= n) break;
        ans = min(ans, arr[en] - arr[st]);
    }
    cout << ans;
}