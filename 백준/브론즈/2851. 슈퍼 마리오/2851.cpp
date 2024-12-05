#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<int> arr;
    for(int i = 0; i < 10; ++i){
        int num;
        cin >> num;

        arr.push_back(num);
    }

    int sum = 0;
    int last = 0;
    for(auto num: arr){
        sum += num;

        if(sum >= 100){
            last = num;
            break;
        }
    }

    if(abs(100 - (sum - last)) >= abs(100 - sum)){
        cout << sum;
    }else{
        cout << sum - last;
    }
}