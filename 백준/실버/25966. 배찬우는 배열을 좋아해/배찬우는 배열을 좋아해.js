const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M, q] = stdin.shift().split(" ").map(Number);

const graph = stdin.slice(0, N).map((str) => str.split(" ").map(Number));

const query = stdin.slice(N).map((str) => str.split(" ").map(Number));

function solution() {
  query.forEach((item) => {
    const [command] = item;

    if (command === 0) {
      const [_, i, j, k] = item;

      graph[i][j] = k;
    } else {
      const [_, i, j] = item;

      const temp = graph[j];
      graph[j] = graph[i];
      graph[i] = temp;
    }
  });

  graph.forEach((item) => console.log(item.join(" ")));
}

solution();
