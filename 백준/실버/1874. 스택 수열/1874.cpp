#include <bits/stdc++.h>

using namespace std;
int arr[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int idx = 0;
    stack<int> st;
    vector<char> ans;
    
    for(int i = 1; i <= n; ++i){
        if(!st.empty() && st.top() == arr[idx]){
            while(!st.empty() && st.top() == arr[idx]){
                ++idx;
                st.pop();
                ans.push_back('-');
            }
        }
        st.push(i);
        ans.push_back('+');
    }

    while(!st.empty() && st.top() == arr[idx]){
        ++idx;
        st.pop();
        ans.push_back('-');
    }

    if(st.empty()){
        for(auto s: ans){
            cout << s << '\n';
        }
    }else{
        cout << "NO";
    }
}