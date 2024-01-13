#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        unordered_map<string, int> m;

        for(int i = 0; i < n; ++i){
            string a, b;
            cin >> a >> b;

            if(m[b]){
                m[b]++;
            }
            else{
                m[b] = 1;
            }
        }
        
        int ans = 1;
        for(auto i: m){
            ans *= (i.second + 1);
        }
        ans -= 1;

        cout << ans << '\n';
    }
}