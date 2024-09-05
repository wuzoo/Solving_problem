const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = stdin[0].split(" ").map(Number);

const direction = (cur) => [cur * 2, cur + 1, cur - 1];

function solution() {
  const cnts = Array.from(Array(200001), () => 0);
  const visited = Array.from(Array(200001), () => 0);

  const q = [[N, 0]];
  visited[N] = 1;
  cnts[N] = 1;

  while (q.length) {
    const [pos, cnt] = q.shift();

    for (const v of direction(pos)) {
      const next = v;

      if (next < 0 || next > 100000) continue;

      if (!visited[next]) {
        visited[next] = visited[pos] + 1;
        cnts[next] += cnts[pos];
        q.push([next, cnt + 1]);
      } else if (visited[next] === visited[pos] + 1) {
        cnts[next] += cnts[pos];
      }
    }
  }

  console.log(`${visited[M] - 1}\n${cnts[M]}`);
}

solution();
