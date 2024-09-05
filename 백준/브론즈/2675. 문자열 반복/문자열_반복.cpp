#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int r; string s;
        cin >> r >> s;

        string result = "";
        for(int i = 0; i < s.length(); ++i){
            for(int j = 0; j < r; ++j){
                result += s[i];
            }
        }

        cout << result << '\n';
    }
}