const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = stdin[0].split(" ").map(Number);
const arr = stdin.slice(1).map((str) => str.split("").map(Number));

const dx = [0, 0, -1, 1];
const dy = [1, -1, 0, 0];

function solution(N, M, arr) {
  const visited = Array.from({ length: N + 1 }, () => Array(N + 1).fill(0));

  function BFS(cx, cy) {
    const q = [];
    q.push([cx, cy, 0]);
    visited[cx][cy] = 1;

    while (q.length) {
      const [x, y, cnt] = q.shift();

      if (x === N - 1 && y === M - 1) {
        return cnt;
      }

      for (let i = 0; i < 4; ++i) {
        const nx = x + dx[i];
        const ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] === 0)
          continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = 1;
        q.push([nx, ny, cnt + 1]);
      }
    }
    return -1;
  }

  console.log(BFS(0, 0) + 1);
}

solution(N, M, arr);
