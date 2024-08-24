const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

let T = +stdin[0];

let idx = 1;
while (T--) {
  const [N, M, W] = stdin[idx++].split(" ").map(Number);

  const edges = stdin
    .slice(idx, idx + M)
    .map((str) => str.split(" ").map(Number));

  idx += M;

  const holes = stdin
    .slice(idx, idx + W)
    .map((str) => str.split(" ").map(Number));

  idx += W;

  function solution() {
    const graph = [];
    const d = Array.from(Array(N + 1), () => 1e9);

    function BellmanFord(start) {
      d[start] = 0;
      for (let i = 0; i < N; ++i) {
        for (let j = 0; j < graph.length; ++j) {
          const [from, to, cost] = graph[j];

          if (d[from] + cost < d[to]) {
            d[to] = d[from] + cost;

            if (i === N - 1) return true;
          }
        }
      }

      return false;
    }

    edges.forEach((item) => {
      const [start, to, cost] = item;

      graph.push([start, to, cost]);
      graph.push([to, start, cost]);
    });

    holes.forEach((item) => {
      const [start, to, cost] = item;

      graph.push([start, to, -cost]);
    });

    console.log(BellmanFord(1) ? "YES" : "NO");
  }

  solution();
}
