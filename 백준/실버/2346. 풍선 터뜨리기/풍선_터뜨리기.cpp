#include <iostream>
#include <deque>
using namespace std;
int step[1001];
int main(){
    int n;
    cin >> n;
    
    deque<int> dq;
    for(int i = 1; i <= n; ++i){
        cin >> step[i];
        dq.push_back(i);
    }

    while(!dq.empty()){
        int idx = dq.front();
        int front = step[idx];
        cout << idx << " ";
        dq.pop_front();
        
        if(dq.empty()) break;

        if(front > 0){
            for(int i = 0; i < front - 1; ++i){
                int frontidx = dq.front();
                dq.pop_front();
                dq.push_back(frontidx);
            }
        }
        else{
            for(int i = front; i < 0; ++i){
                int backidx = dq.back();
                dq.pop_back();
                dq.push_front(backidx);
            }
        }
    }
}