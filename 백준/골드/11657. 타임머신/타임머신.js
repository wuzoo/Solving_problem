const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = stdin[0].split(" ").map(Number);
const arr = stdin.slice(1).map((str) => str.split(" ").map(Number));

const d = Array.from(Array(N + 1), () => Infinity);
const graph = [];

function bellmanFord(start) {
  d[start] = 0;

  for (let i = 1; i <= N; ++i) {
    for (let j = 0; j < M; ++j) {
      const [start, to, cost] = graph[j];

      if (d[start] === Infinity) continue;

      if (d[start] + cost < d[to]) {
        d[to] = d[start] + cost;

        if (i === N) {
          return true;
        }
      }
    }
  }
  return false;
}

function solution() {
  arr.forEach((item) => {
    const [start, end, cost] = item;

    graph.push([start, end, cost]);
  });

  const isNegative = bellmanFord(1);

  if (isNegative) console.log(-1);
  else {
    d.slice(2).forEach((distance) =>
      console.log(distance === Infinity ? "-1" : distance)
    );
  }
}

solution();
