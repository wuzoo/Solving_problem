#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int cnt[1000001];
int ans[1000001];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    stack<int> st;
    for(int i = n - 1; i >= 0; --i){
        while(!st.empty() && cnt[arr[i]] >= cnt[st.top()]){
            st.pop();
        }
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }

    for(int i = 0; i < n; ++i){
        cout << ans[i] << ' ';
    }
}