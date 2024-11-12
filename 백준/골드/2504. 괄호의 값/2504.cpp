#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    stack<char> st;

    int sum = 0;
    int tmp = 1;

    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '('){
            tmp *= 2;
            st.push('(');
        }
        if(s[i] == '['){
            tmp *= 3;
            st.push('[');
        }
        if(s[i] == ')'){
            if(st.empty() || st.top() != '('){
                sum = 0;
                break;
            }
            if(s[i - 1] == '('){
                sum += tmp;
            }
            tmp /= 2;
            st.pop();
        }
        if(s[i] == ']'){
            if(st.empty() || st.top() != '['){
                sum = 0;
                break;
            }
            if(s[i - 1] == '['){
                sum += tmp;
            }
            tmp /= 3;
            st.pop();
        }
    }
    if(!st.empty()){
        sum = 0;
    }
    cout << sum;
}