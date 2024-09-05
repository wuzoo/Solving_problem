#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string func;
        int n;
        cin >> func >> n;

        deque<int> dq;

        char c;
        cin >> c;
        for(int i = 0; i < n; ++i){
            int num;
            cin >> num;
            dq.push_back(num);
            if(i != n - 1) cin >> c;
        }
        cin >> c;

        bool error = false;
        bool is_reverse = false;
        for(int i = 0; i < func.length(); ++i){
            char order = func[i];

            if(order == 'R'){
                is_reverse = !is_reverse;
            }
            else{
                if(dq.size() == 0){
                    error = true;
                    break;
                }
                if(!is_reverse){
                    dq.pop_front();
                }
                else{
                    dq.pop_back();
                }
            }
        }
        if(!error){
            cout << "[";
            if(!is_reverse){
                while(!dq.empty()){
                    if(dq.size() != 1) cout << dq.front() << ',';
                    else cout << dq.front();
                    dq.pop_front();
                }
            }
            else{
                while(!dq.empty()){
                    if(dq.size() != 1) cout << dq.back() << ',';
                    else cout << dq.back();
                    dq.pop_back();
                }
            }
            cout << "]\n";
        }
        else{
            cout << "error\n";
        }
    }
}   