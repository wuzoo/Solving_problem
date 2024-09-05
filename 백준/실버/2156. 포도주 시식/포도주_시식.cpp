#include <iostream>
#include <algorithm>
using namespace std;

long long dp[10001];
int arr[10001];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[2], max(arr[1] + arr[3], arr[3] + arr[2]));
    for(int i = 4; i <= n; ++i){
        dp[i] = max(dp[i - 1], max(dp[i - 3] + arr[i - 1] + arr[i], arr[i] + dp[i - 2]));
    }

    cout << dp[n];
}