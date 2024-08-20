const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = stdin[0].split(" ").map(Number);
const xy = stdin.slice(1, N + 1).map((str) => str.split(" ").map(Number));
const uv = stdin.slice(N + 1).map((str) => str.split(" ").map(Number));

function solution() {
  const visited = Array.from({ length: 101 }, () => 0);
  const hole = Array.from({ length: 101 }, () => 0);

  xy.forEach(([start, end]) => (hole[start] = end));
  uv.forEach(([start, end]) => (hole[start] = end));

  let index = 0;
  const q = [[1, 0]];
  visited[1] = 1;
  while (q.length > index) {
    const [start, cnt] = q[index++];

    if (start === 100) {
      console.log(cnt);
      break;
    }

    for (let i = 1; i <= 6; ++i) {
      let next = start + i;

      if (next > 100) continue;

      if (hole[next]) {
        next = hole[next];
      }

      if (visited[next]) continue;

      visited[next] = 1;
      q.push([next, cnt + 1]);
    }
  }
}

solution();
