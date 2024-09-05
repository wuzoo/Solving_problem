#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> map;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        map[s]++;
    }

    vector<string> ans;
    for(int i = 0; i < m; ++i){
        string s;
        cin >> s;

        if(map[s]){
            ans.push_back(s);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << '\n';
    }
}