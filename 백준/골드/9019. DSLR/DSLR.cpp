#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int map[10001];
char cmds[4] = {'D', 'S', 'L', 'R'};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;

        queue<pair<int, string>> q;
        q.push({a, ""});
        map[a] = 1;
        while(!q.empty()){
            int origin = q.front().first;
            string cmd = q.front().second;
            q.pop();

            if(origin == b){
                cout << cmd << '\n';
                memset(map, 0, sizeof(map));
                break;
            }

            for(int i = 0; i < 4; ++i){
                string nc = cmd + cmds[i];
                
                if(cmds[i] == 'D'){
                    int num = (origin * 2) % 10000;

                    if(map[num]) continue;

                    map[num] = 1;
                    q.push({num, nc});
                }
                else if(cmds[i] == 'S'){
                    int num = ((origin - 1) + 10000) % 10000;
                    
                    if(map[num]) continue;

                    map[num] = 1;
                    q.push({num, nc});
                }
                else if(cmds[i] == 'L'){
                    int num = (origin % 1000) * 10 + (origin / 1000);
                    if(map[num]) continue;

                    map[num] = 1;
                    q.push({num, nc});
                }
                else if(cmds[i] == 'R'){
                    int num = origin / 10 + (origin % 10) * 1000;
                    if(map[num]) continue;

                    map[num] = 1;
                    q.push({num, nc});
                }
            }
        }
    }
}
