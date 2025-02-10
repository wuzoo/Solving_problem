#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    for(int i = 0; i < n; ++i){
        char c; cin >> c;
        v.push_back(c - '0');
    }

    stack<int> st;
    int cnt = 0;
    for(auto num: v){    
        while(!st.empty() && st.top() < num && cnt < k){
            st.pop();
            cnt++;

            if(cnt == k) break;
        }
        
        st.push(num);
    }

    if(cnt < k){
        while(cnt < k){
            st.pop();
            cnt++;
        }
    }

    string ans = "";
    while(!st.empty()){
        int num = st.top();
        st.pop();

        ans += to_string(num);
    }

    for(int i = ans.length() - 1; i >= 0; --i){
        cout << ans[i];
    }
}