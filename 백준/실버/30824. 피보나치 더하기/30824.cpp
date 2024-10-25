#include <bits/stdc++.h>

using namespace std;
long long dp[101];

long long fi(int idx){
    if(dp[idx]) return dp[idx];

    if(idx == 1 || idx == 2){
        return dp[idx] = 1;
    }

    return dp[idx] = fi(idx - 1) + fi(idx - 2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;
    
    fi(100);

    while(t--){
        int a;
        long long b;
        cin >> a >> b;

        bool flag = false;
        if(a == 1){
            for(int i = 1; i <= 100; ++i){
                if(dp[i] == b){
                    cout << "YES";
                    flag = true;
                    break;
                }
            }
        }else if(a == 2){
            for(int i = 1; i <= 100; ++i){
                for(int j = 1; j <= 100; ++j){
                    if(dp[i] + dp[j] == b){
                        cout << "YES";
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
        }else{
            for(int i = 1; i <= 100; ++i){
                for(int j = 1; j <= 100; ++j){
                    for(int k = 1; k <= 100; ++k){
                        if(dp[i] + dp[j] + dp[k] == b){
                            cout << "YES";
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
        }

        if(!flag) cout << "NO";

        cout << '\n';
    }
    
}