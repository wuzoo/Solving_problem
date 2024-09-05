const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin[0];
const arr = stdin.slice(1).map((str) => str.split("").map(Number));

const dx = [0, 0, -1, 1];
const dy = [1, -1, 0, 0];

function solution(N, arr) {
  const visited = Array.from({ length: N + 1 }, () => Array(N + 1).fill(0));
  const answer = [];

  function DFS(x, y) {
    let cnt = 1;
    for (let i = 0; i < 4; ++i) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] === 0) continue;
      if (visited[nx][ny]) continue;

      visited[nx][ny] = 1;
      cnt += DFS(nx, ny);
    }
    return cnt;
  }

  let cnt = 0;
  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < N; ++j) {
      if (!visited[i][j] && arr[i][j] !== 0) {
        visited[i][j] = 1;
        const home_cnt = DFS(i, j);
        cnt++;
        answer.push(home_cnt);
      }
    }
  }
  answer.sort((a, b) => a - b);

  [cnt].concat(answer).forEach((num) => console.log(num));
}

solution(N, arr);
