const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, K] = stdin[0].split(" ").map(Number);

const INF = 100000;

function solution() {
  const visited = Array.from({ length: INF + 1 }, () => 0);

  const q = [[N, 0]];
  visited[N] = 1;

  while (q.length) {
    const [node, cost] = q.shift();

    if (node === K) {
      console.log(cost);
      return;
    }

    for (const next of [node * 2, node + 1, node - 1]) {
      if (visited[next] || next < 0 || next > INF) continue;

      if (next === node * 2) {
        q.unshift([next, cost]);
      } else {
        q.push([next, cost + 1]);
      }
      visited[next] = 1;
    }
  }
}

solution();
