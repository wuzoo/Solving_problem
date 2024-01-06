#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    unordered_map<string ,int> aton;
    unordered_map<int, string> ntoa;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;

        aton[s] = i + 1;
        ntoa[i + 1] = s;
    }

    for(int i = 0; i < m; ++i){
        string s;
        cin >> s;

        if(s[0] >= '1' && s[0] <= '9'){
            int num = stoi(s);
            cout << ntoa[num] << '\n';
        }
        else{
            cout << aton[s] << '\n';
        }
    }
}