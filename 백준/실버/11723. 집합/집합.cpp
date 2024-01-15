#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int set[21];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int m;
    cin >> m;
    while(m--){
        string cmd;
        cin >> cmd;
        int x;
        if(cmd == "add"){
            cin >> x;
            set[x] = 1;
        }
        else if(cmd == "remove"){
            cin >> x;
            set[x] = 0;
        }
        else if(cmd == "check"){
            cin >> x;
            if(set[x] == 1){
                cout << 1;
            }
            else{
                cout << 0;
            }
            cout << '\n';
        }
        else if(cmd == "toggle"){
            cin >> x;
            if(set[x] == 1){
                set[x] = 0;
            }
            else{
                set[x] = 1;
            }
        }
        else if(cmd == "all"){
            for(int i = 1; i <= 20; ++i){
                set[i] = 1;
            }
        }
        else if(cmd == "empty"){
            memset(set, 0, sizeof(set));
        }
    }
}