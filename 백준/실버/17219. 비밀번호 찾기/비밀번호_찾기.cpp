#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    unordered_map<string, string> map;
    for(int i = 0; i < n; ++i){
        string site, pwd;
        cin >> site >> pwd;

        map[site] = pwd;
    }
    for(int i = 0; i < m; ++i){
        string s;
        cin >> s;

        cout << map[s] << '\n';
    }
}