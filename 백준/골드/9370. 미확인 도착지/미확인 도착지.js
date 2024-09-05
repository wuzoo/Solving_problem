const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

let T = +stdin[0];

let index = 1;
while (T--) {
  const [n, m, t] = stdin[index].split(" ").map(Number);
  index++;

  const [s, g, h] = stdin[index].split(" ").map(Number);
  index++;

  const abd = [];
  for (let i = 0; i < m; ++i) {
    const [a, b, d] = stdin[index].split(" ").map(Number);
    index++;

    abd.push([a, b, d]);
  }

  const dests = [];
  for (let i = 0; i < t; ++i) {
    const x = +stdin[index];
    index++;

    dests.push(x);
  }

  solution();

  function solution() {
    const answer = [];
    const graph = Array.from({ length: n + 1 }, () => []);

    abd.forEach((item) => {
      const [start, end, dist] = item;

      graph[start].push([end, dist]);
      graph[end].push([start, dist]);
    });

    function Dijkstra(start) {
      const d = Array.from({ length: n + 1 }, () => Infinity);

      const q = [[start, 0]];
      d[start] = 0;

      let idx = 0;
      while (q.length > idx) {
        const [curNode, curCost] = q[idx++];

        if (d[curNode] < curCost) continue;

        for (const v of graph[curNode]) {
          const node = v[0];
          const dist = curCost + v[1];

          if (dist < d[node]) {
            q.push([node, dist]);
            q.sort((a, b) => a[1] - b[1]);
            d[node] = dist;
          }
        }
      }
      return d;
    }

    const fromS = Dijkstra(s);
    const fromG = Dijkstra(g);
    const fromH = Dijkstra(h);

    dests.forEach((dest) => {
      const min = Math.min(
        fromG[s] + fromG[h] + fromH[dest],
        fromG[dest] + fromG[h] + fromH[s]
      );

      if (Number.isFinite(min)) {
        if (min === fromS[dest]) {
          answer.push(dest);
        }
      }
    });

    console.log(answer.sort((a, b) => a - b).join(" "));
  }
}
