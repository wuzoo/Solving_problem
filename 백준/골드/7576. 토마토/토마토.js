const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [M, N] = stdin[0].split(" ").map(Number);
const arr = stdin.slice(1).map((str) => str.split(" ").map(Number));

const dx = [0, 0, -1, 1];
const dy = [1, -1, 0, 0];

function solution(M, N, arr) {
  const visited = Array.from({ length: N }, () => Array(M).fill(0));
  let zerosum = 0;

  const q = [];

  arr.forEach((row, i) =>
    row.forEach((num, ci) => {
      if (num === 1) q.push([i, ci, 0]);
      else if (num === -1) visited[i][ci] = -1;
      else zerosum++;
    })
  );

  if (q.length === N * M) {
    console.log(0);
    return;
  }

  if (q.length === 0 && zerosum) {
    console.log(-1);
    return;
  }

  q.forEach((item) => {
    const [x, y, cnt] = item;

    visited[x][y] = 1;
  });

  let max = 0;
  let index = 0;
  while (q.length > index) {
    const [x, y, cnt] = q[index++];

    if (cnt > max) {
      max = cnt;
    }

    for (let i = 0; i < 4; ++i) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] === -1)
        continue;
      if (visited[nx][ny] || visited[nx][ny] === -1) continue;

      visited[nx][ny] = 1;
      q.push([nx, ny, cnt + 1]);
    }
  }

  for (let i = 0; i < N; ++i) {
    for (let j = 0; j < M; ++j) {
      if (visited[i][j] === 0) {
        console.log(-1);
        return;
      }
    }
  }
  console.log(max);
}

solution(M, N, arr);
