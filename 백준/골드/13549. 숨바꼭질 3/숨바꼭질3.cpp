#include <iostream>
#include <deque>
using namespace std;

int N, K;
int visited[100001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    deque<pair<int, int>> dq;
    dq.push_back({N, 0});
    visited[N] = 1;

    while(dq.size()){
        int node = dq.front().first;
        int cost = dq.front().second;
        dq.pop_front();

        if(node == K){
            cout << cost;
            break;
        }

        if(node * 2 <= 100000 && !visited[node * 2]){
            dq.push_front({node * 2, cost});
            visited[node * 2] = 1;
        }
        if(node + 1 <= 100000 && !visited[node + 1]){
            dq.push_back({node + 1, cost + 1});
            visited[node + 1] = 1;
        }
        if(node - 1 >= 0 && !visited[node - 1]){
            dq.push_front({node - 1, cost + 1});
            visited[node - 1] = 1;
        }
    }

    return 0;
}