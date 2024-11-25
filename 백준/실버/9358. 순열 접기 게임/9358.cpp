#include <bits/stdc++.h>

using namespace std;

int arr[101];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;
    int round = 0;
    while(t--){
        round++;

        int n;
        cin >> n;

        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        double len = double(n);
        
        while(len > 2){
            int st = 0;
            int en = len - 1;

            len = ceil(len / 2);

            for(int i = 0; i < int(len); ++i){
                arr[i] = arr[st] + arr[en];
                st++;
                en--;
            }
        }
        
        string ans;
        if(arr[0] > arr[1]) ans = "Alice";
        else ans = "Bob";

        cout << "Case #" << round << ": " << ans << '\n';
    }
}