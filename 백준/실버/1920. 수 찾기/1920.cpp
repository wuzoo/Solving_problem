#include <bits/stdc++.h>

using namespace std;

int A[100001];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<int, int> map;
    for(int i = 0; i < N; ++i){
        cin >> A[i];

        map.insert({A[i], 1});
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; ++i){
        int num;
        cin >> num;

        if(map.find(num) == map.end()){
            cout << 0;
        }else{
            cout << 1;
        }
        cout << '\n';
    }
}