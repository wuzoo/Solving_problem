#include <bits/stdc++.h>

using namespace std;

int arr[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        vector<int> v;
        for(int i = 1; i <= 9; ++i){
            int num;
            cin >> num;

            for(int j = 0; j < num; ++j){
                if(i == 6) v.push_back(9);
                else v.push_back(i);
            }
        }

        sort(v.begin(), v.end(), greater<int>());

        vector<int> result;
        int st = 0;
        int en = v.size() - 1;
        
        bool flag = true;
        for(int i = 0; i < v.size(); ++i){
            if(flag){
                arr[st++] = v[i];
                flag = false;
            }else{
                arr[en--] = v[i];
                flag = true;
            }
        }

        for(int i = 0; i < v.size(); ++i){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
}