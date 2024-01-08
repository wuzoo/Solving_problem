#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

long long dp[101][10];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;

    for(int i = 1; i <= 9; ++i){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; ++i){
        for(int j = 0; j <= 9; ++j){
            if(j == 0){
                dp[i][j] = dp[i - 1][j + 1];
            }
            else if(j == 9){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];
            }
            dp[i][j] %= INF;
        }
    }

    long long sum = 0;
    for(int i = 0; i <= 9; ++i){
        sum += dp[n][i];
    }
    cout << sum % INF;
}