#include <iostream>
#include <stack>
using namespace std;

int main(){
    while(true){
        string s;
        getline(cin, s);
        if(s == "."){
            break;
        }

        string result;
        string a = "()";
        string b = "[]";

        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']'){
                result.push_back(s[i]);
            }

            if(result.length() >= 2 && (result.substr(result.length() - 2) == a || result.substr(result.length() - 2) == b)){
                result.resize(result.length() - 2);
            }
        }
        if(result.empty()){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
}