#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    queue<int> circle;
    for(int i = 1; i <= n; ++i){
        circle.push(i);
    }

    vector<int> ans;
    while(!circle.empty()){
        int idx = 0;
        for(int i = 0; i < k - 1; ++i){
            int front = circle.front();
            circle.pop();
            circle.push(front);
        }
        ans.push_back(circle.front());
        circle.pop();
    }
    cout << "<";
    for(int i = 0; i < ans.size(); ++i){
        if(i == ans.size() - 1) cout << ans[i] << ">";
        else cout << ans[i] << ", ";
    }
}