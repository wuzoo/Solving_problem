const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [A, K] = stdin[0].split(" ").map(Number);

function solution2() {
  const visited = new Array(1000001).fill(0);

  const dx = (cur) => [cur * 2, cur + 1];

  const q = [[A, 0]];
  visited[A] = 1;
  while (q.length) {
    const [node, cnt] = q.shift();

    if (node === K) {
      console.log(cnt);
      return;
    }

    for (const v of dx(node)) {
      if (v > K) continue;

      if (!visited[v]) {
        visited[v] = 1;
        q.push([v, cnt + 1]);
      }
    }
  }
}

solution2();
