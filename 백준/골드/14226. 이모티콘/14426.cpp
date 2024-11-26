#include <bits/stdc++.h>

using namespace std;

int s;
int visited[1001][1001];

void bfs(int st){
    queue<pair<pair<int, int>, int>> q;
    q.push({{st, 0}, 0});
    visited[st][0] = 1;

    while(!q.empty()){
        int cur = q.front().first.first; // 화면에 표시되는 이모티콘 개수
        int time = q.front().first.second; // 시간
        int imoCnt = q.front().second; // 클립보드 복사 이미지 개수
        q.pop();

        if(cur == s){
            cout << time;
            break;
        }

        if(cur + imoCnt <= 1000 && !visited[cur + imoCnt][imoCnt]){
            visited[cur + imoCnt][imoCnt] = 1;
            q.push({{cur + imoCnt, time + 1}, imoCnt});
        }
        if(cur > 0 && !visited[cur - 1][imoCnt]){
            visited[cur - 1][imoCnt] = 1;
            q.push({{cur - 1, time + 1}, imoCnt});
        }
        if(!visited[cur][cur]){
            visited[cur][cur] = 1;
            q.push({{cur, time + 1}, cur});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    
    bfs(1);
}