#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;

    queue<int> original;
    stack<int> other;
    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;
        original.push(num);
    }

    int idx = 1;
    while(!original.empty()){
        int front = original.front();
        if(front == idx){
            ++idx;
            original.pop();
        }
        else{
            if(!other.empty()){
                int otherfront = other.top();
                if(otherfront == idx){
                    ++idx;
                    other.pop();
                    continue;
                }
            }
            other.push(front);
            original.pop();
        }
    }
    
    bool canSolve = true;
    while(!other.empty()){
        int top = other.top();
        if(top != idx){
            canSolve = false;
            break;
        }
        else{
            ++idx;
            other.pop();
        }
    }
    cout << (canSolve ? "Nice\n" : "Sad\n");
}