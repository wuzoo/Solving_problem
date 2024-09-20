#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

int arr[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int st = 0;
    int en = n - 1;
    int min = INF;
    pair<int, int> ans;
    while(st < en){
        int sum = arr[st] + arr[en];

        if(min > abs(sum)){
            min = abs(sum);
            ans = {arr[st], arr[en]};
        }

        if(sum < 0){
            st++;
        }else if(sum > 0){
            en--;
        }else if(sum == 0){
            ans = {arr[st], arr[en]};
            break;
        }
    }

    cout << ans.first << ' ' << ans.second;
}