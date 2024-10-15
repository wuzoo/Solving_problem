#include <bits/stdc++.h>

using namespace std;

int n, m;
char arr[16];
int ans[16];
int visited[16];
vector<string> result;

struct cmp{
    bool operator()(char a, char b){
        return a - '0' < b - '0';
    }
};

void DFS(int k, int idx){
    if(k == n){
        int cnt1 = 0;
        int cnt2 = 0;
        string tmp = "";
        for(int i = 0; i < n; ++i){
            if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u'){
                cnt1++;
            }else{
                cnt2++;
            }
            tmp += ans[i];
        }
        if(tmp.length() != n) return;

        if(cnt1 >= 1 && cnt2 >= 2){
            result.push_back(tmp);
        }
        return;
    }
    for(int i = idx; i < m; ++i){
        if(!visited[i]){
            ans[k] = arr[i];
            visited[i] = 1;
            DFS(k + 1, i);
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        cin >> arr[i];       
    }

    sort(arr, arr + m, cmp());

    DFS(0, 0);

    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << '\n';
    }
}