#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string i, string j){
    if(i.length() != j.length()){
        return i.length() < j.length();
    }
    else{
        return i < j;
    }
}

int main(){
    int n;
    cin >> n;

    vector<string> arr(n);

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), cmp);

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for(int i = 0; i < arr.size(); ++i){
        cout << arr[i] << '\n';
    }
}