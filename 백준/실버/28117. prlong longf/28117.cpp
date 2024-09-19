#include <bits/stdc++.h>
using namespace std;

string str = "";
int dp[81];

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  cout.tie(nullptr);

  int n;
  cin >> n;
  cin >> str;

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i < n; ++i){
    dp[i] = dp[i - 2] + dp[i - 1];
  }

  int ans = 1;
  int cnt = 0;

  str = str + 't';
  
  for(int i = 0; i < n + 1; ++i){
    if(i + 3 <= n && str[i] == 'l' && str[i + 1] == 'o' && str[i + 2] == 'n' && str[i + 3] == 'g'){
      cnt++;
      i += 3;
    }else{
      ans *= dp[cnt];
      cnt = 0;
    }
  }

  cout << ans;
}