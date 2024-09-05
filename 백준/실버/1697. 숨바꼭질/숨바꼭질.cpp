#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int visited[100001];
int step[100001];
int n, k;
queue<int> pos;

int main(){
    cin >> n >> k;

    pos.push(n);
    visited[n] = 1;
    while(!pos.empty()){
        int x = pos.front();
        pos.pop();

        if(x == k){
            cout << step[x];
            break;
        }

        int leftgo = x - 1;
        int rightgo = x + 1;
        int teleport = 2 * x;

        if(leftgo >= 0){
            if(!visited[leftgo]){
                visited[leftgo] = 1;
                step[leftgo] = step[x] + 1;
                pos.push(leftgo);
            }
        }
        if(rightgo <= MAX){
            if(!visited[rightgo]){
                visited[rightgo] = 1;
                step[rightgo] = step[x] + 1;
                pos.push(rightgo);
            }
        }
        if(teleport <= MAX){
            if(!visited[teleport]){
                visited[teleport] = 1;
                step[teleport] = step[x] + 1;
                pos.push(teleport);
            }
        }
    }
    
    return 0;
}