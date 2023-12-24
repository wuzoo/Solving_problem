#include <iostream>
#include <algorithm>
using namespace std;

int num[11];
char sign[10];
bool visited[10];
char s[4] = {'+', '-', '*', '/'};
int mymax = -1000000001;
int mymin = 1000000001;
int n;

void dfs_cal(int idx, int sum){
    if(idx == n){
        mymax = max(mymax, sum);
        mymin = min(mymin, sum);
        return;
    }
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            visited[i] = true;
            switch (sign[i]){
                case '+': {
                    dfs_cal(idx + 1, sum + num[idx]);
                    break;
                }
                case '-':{
                    dfs_cal(idx + 1, sum - num[idx]);
                    break; 
                }
                case '*':{
                    dfs_cal(idx + 1, sum * num[idx]);
                    break;
                }
                case '/':{
                    dfs_cal(idx + 1, sum / num[idx]);
                    break;
                }
            }
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num[i];
    }

    int tmp[4];
    int idx = 0;
    for(int i = 0; i < 4; ++i){
        cin >> tmp[i];
        for(int j = 0; j < tmp[i]; ++j){
            sign[idx] = s[i];
            ++idx;
        }
    }

    dfs_cal(1, num[0]);

    cout << mymax << '\n' << mymin;
}