const fs = require("fs");
let [N, ...graph] = fs.readFileSync("ex.txt").toString().trim().split("\n");

N = +N;
graph = graph.map((str) => str.split(" ").map(Number));

const dx = [0, 1];
const dy = [1, 0];

function solution() {
  const visited = Array.from(Array(N), () => Array(N).fill(0));

  const q = [[0, 0, 0]];
  visited[0][0] = 1;
  while (q.length) {
    const [x, y, cnt] = q.shift();

    if (x === N - 1 && y === N - 1) {
      return "HaruHaru";
    }

    for (let i = 0; i < 2; ++i) {
      const num = graph[x][y];

      const nx = x + dx[i] * num;
      const ny = y + dy[i] * num;

      if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      if (visited[nx][ny]) continue;

      visited[nx][ny] = 1;
      q.push([nx, ny, cnt + 1]);
    }
  }

  return "Hing";
}

console.log(solution());
