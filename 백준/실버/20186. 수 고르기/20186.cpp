#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[5001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<>());

    int sum = 0;
    for(int i = 0; i < k; ++i){
        sum += arr[i];
    }
    
    int kSum = 0;
    for(int i = 0; i <= k - 1; ++i){
        kSum += i;
    }

    cout << sum - kSum;
}