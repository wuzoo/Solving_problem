#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s, boom;
    cin >> s >> boom;

    string result;
    for(int i = 0; i < s.length(); ++i){
        result.push_back(s[i]);

        if(result.length() >= boom.length() && result.substr(result.length() - boom.length()) == boom){
            result.resize(result.length() - boom.length());      
        }
    }

    if(result.length() == 0) cout << "FRULA";
    else cout << result;
}
