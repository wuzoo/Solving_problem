#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        string result;

        string vps = "()";
        for(int i = 0; i < s.length(); ++i){
            result.push_back(s[i]);

            if(result.length() >= 2 && result.substr(result.length() - 2) == vps){
                result.resize(result.length() - 2);
            }
        }
        if(result.empty()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
}