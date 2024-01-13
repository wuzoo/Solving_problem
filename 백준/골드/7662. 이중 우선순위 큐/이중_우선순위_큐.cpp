#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#define INF 0x7fffffff
using namespace std;

unordered_map<int, int> cnt;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        priority_queue<int, vector<int>, less<int>> max_pq;
        for(int i = 0; i < k; ++i){
            char c;
            cin >> c;
            if(c == 'I'){
                int num;
                cin >> num;
                max_pq.push(num);
                min_pq.push(num);
                cnt[num]++;
                
            }
            else{
                int num;
                cin >> num;
                if(num == -1){
                    if(min_pq.empty()) continue;
                    if(cnt[min_pq.top()]){
                        cnt[min_pq.top()]--;
                    }
                    min_pq.pop();
                    
                }
                else if(num == 1){
                    if(max_pq.empty()) continue;
                    if(cnt[max_pq.top()]){
                        cnt[max_pq.top()]--;
                    }
                    max_pq.pop();
                }
                while(!min_pq.empty() && cnt[min_pq.top()] == 0){
                    min_pq.pop();
                }
                while(!max_pq.empty() && cnt[max_pq.top()] == 0){
                    max_pq.pop();
                }
            }
        }
        while(!min_pq.empty() && cnt[min_pq.top()] == 0){
            min_pq.pop();
        }
        while(!max_pq.empty() && cnt[max_pq.top()] == 0){
            max_pq.pop();
        }

        if(min_pq.empty() || max_pq.empty()) cout << "EMPTY\n";
        else{
            cout << max_pq.top() << ' ' << min_pq.top() << '\n';   
        }
        cnt.clear();
    }
}