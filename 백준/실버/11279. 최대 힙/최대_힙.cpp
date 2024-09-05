#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;

        if(x > 0){
            pq.push(x);
        }
        else if(x == 0){
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else{
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}