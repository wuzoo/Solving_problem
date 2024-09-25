    #include <bits/stdc++.h>
    
    using namespace std;
    int arr[100001];
    
    int main() {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
        priority_queue<int, vector<int>, greater<int>> pq;

        int n;
        cin >> n;

        if(n == 1){
            cout << 0;
            return 0;
        }

        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            pq.push(arr[i]);
        }


        int sum = 0;
        while(pq.size()){
            int top = pq.top();
            pq.pop();
            
            int second = 0;
            if(!pq.empty()){
                second = pq.top();
                pq.pop();
            }

            sum += top + second;

            if(pq.empty()) break;

            pq.push(top + second);
        }

        cout << sum;
    }