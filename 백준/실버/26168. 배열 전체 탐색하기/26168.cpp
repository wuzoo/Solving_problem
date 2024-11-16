#include <bits/stdc++.h>

using namespace std;

long long arr[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < m; ++i){
        int input;
        cin >> input;

        if(input == 1){
            long long i;
            cin >> i;

            int idx = lower_bound(arr, arr + n, i) - arr;
            cout << n - idx << '\n';
        }
        if(input == 2){
            long long i;
            cin >> i;

            int idx = upper_bound(arr, arr + n, i) - arr;
            cout << n - idx << '\n';
        }
        if(input == 3){
            long long i, j;
            cin >> i >> j;

            int l = lower_bound(arr, arr + n, i) - arr;
            int u = upper_bound(arr, arr + n, j) - arr;

            cout << u - l << '\n';
        }
    }
}