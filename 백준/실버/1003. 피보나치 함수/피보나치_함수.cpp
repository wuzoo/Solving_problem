#include <iostream>
using namespace std;

int dp[41];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        if(n == 1){
            cout << 0 << ' ' << 1 << '\n';
        }
        else if(n == 0){
            cout << 1 << ' ' << 0 << '\n';
        }
        else{
            cout << dp[n - 2] << ' ' << dp[n - 1] << '\n';
        }
    }
}