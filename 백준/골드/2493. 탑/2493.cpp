#include <bits/stdc++.h>

using namespace std;
int arr[500001];
int result[500001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    stack<pair<int, int>> st;
    for(int i = 0; i < n; ++i){
        while(!st.empty()){
            int t = st.top().second;

            if(t > arr[i]){
                result[i] = st.top().first;
                break;
            }

            st.pop();
        }

        if(st.empty()){
            result[i] = 0;
        }

        st.push({i + 1, arr[i]});
    }

    for(int i = 0; i < n; ++i){
        cout << result[i] << ' ';
    }
}