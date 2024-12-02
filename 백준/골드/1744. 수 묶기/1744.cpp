#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
 
    vector<int> pos;
    vector<int> neg;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num > 0) pos.push_back(num);
        else neg.push_back(num);
    }
 
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int sum = 0;
 
    int pSize = pos.size();
    if (pSize % 2 != 0) {
        sum += pos[0];
    }
    for (int i = pSize - 1; i > 0; i -= 2) {
        int big = pos[i];
        int small = pos[i - 1];
        int mul = 0;

        if(big == 1 || small == 1){
            mul = big + small;
        }else{
            mul = big * small;
        }
        
        sum += mul;
    }
 
    int nSize = neg.size();
    if (nSize % 2 != 0 && nSize > 0) {
        sum += neg[neg.size() - 1];
    }
    for (int i = 0; i < nSize - 1; i += 2) {
        int small = neg[i];
        int big = neg[i + 1];
        int mul = small * big;
        
        sum += mul;
    }
 
    cout << sum;
    
 
    return 0;
}
