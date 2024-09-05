#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, m;
    string s;

    cin >> n >> m >> s;

    int ans = 0;
    for(int i = 0; i < m; ++i){
        if(s[i] == 'O'){
            continue;
        }
        else{
            int k = 0;
            while(s[i + 1] == 'O' && s[i + 2] == 'I'){
                k++;
                if(k == n){
                    ans++;
                    k--;
                }
                i += 2;
            }
        }
    }
    cout << ans;
}