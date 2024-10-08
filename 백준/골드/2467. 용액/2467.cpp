#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i =0 ; i < n; ++i){
        cin >> arr[i];
    }

    int st = 0;
    int en = n - 1;

    int min_val = 2000000001;
    pair<int, int> ans;
    while(st < en){
        int mid = arr[st] + arr[en];

        if(abs(mid) < min_val){
            min_val = abs(mid);
            ans = {st, en};
        }
        if(mid < 0){
            st++;
        }
        else{
            en--;
        }
    }

    cout << arr[ans.first] << ' ' << arr[ans.second];
}