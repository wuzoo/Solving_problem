#include <iostream>
#include <algorithm>
using namespace std;

int MAX = -1000000001;
int MIN = 1000000001;
int N;
int signs[4];
int arr[12];

void DFS(int, int);
int main(){
  cin >> N;

  for(int i = 0; i < N; ++i){
    cin >> arr[i];
  }

  for(int i = 0; i < 4; ++i){
    cin >> signs[i];
  }

  DFS(0, arr[0]);

  cout << MAX << "\n" << MIN;
}
void DFS(int k, int num){
    if(k == N - 1){
      MAX = max(num, MAX);
      MIN = min(num, MIN);
      return;
    }

    for(int i = 0; i < 4; ++i){
      if(signs[i]){
        signs[i] -= 1;
        if(i == 0){
          DFS(k + 1, num + arr[k + 1]);
        }
        if(i == 1){
          DFS(k + 1, num - arr[k + 1]);
        }
        if(i == 2){
          DFS(k + 1, num * arr[k + 1]);
        }
        if(i == 3){
          DFS(k + 1, num / arr[k + 1]);
        }
        signs[i] += 1;
      }
    }
  }