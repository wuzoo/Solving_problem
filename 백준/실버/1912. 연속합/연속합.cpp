#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];
int arr[100001];
int ret;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    ret = arr[0];
    dp[0] = arr[0];
    for(int i = 1; i < n; ++i){
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ret = max(dp[i], ret);
    }

    cout << ret;
}