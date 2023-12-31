#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b){ // {절댓값. 실제값}
        if(a.first != b.first){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int main(){
    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;

        if(x != 0){
            pq.push({abs(x), x});
        }
        else{
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
    }
    return 0;
}