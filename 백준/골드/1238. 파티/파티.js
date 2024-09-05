const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M, X] = stdin[0].split(" ").map(Number);
const arr = stdin.slice(1).map((str) => str.split(" ").map(Number));

function solution() {
  const graph = Array.from(Array(N + 1), () => []);
  const reverseGraph = Array.from(Array(N + 1), () => []);

  arr.forEach((item) => {
    const [start, end, cost] = item;

    graph[start].push([end, cost]);
    reverseGraph[end].push([start, cost]);
  });

  function Dijkstra(graph) {
    const d = Array.from(Array(N + 1), () => Infinity);

    const q = [[X, 0]];
    d[X] = 0;

    let idx = 0;
    while (q.length > idx) {
      const [curN, curD] = q[idx++];

      if (d[curN] < curD) continue;

      for (const v of graph[curN]) {
        const node = v[0];
        const dist = v[1] + curD;

        if (dist < d[node]) {
          q.push([node, dist]);
          d[node] = dist;
        }
      }
    }
    return d;
  }

  const numToX = Dijkstra(reverseGraph);
  const xToNum = Dijkstra(graph);

  let max = 0;
  for (let i = 1; i <= N; ++i) {
    const sum = numToX[i] + xToNum[i];

    max = Math.max(max, sum);
  }

  console.log(max);
}

solution();
