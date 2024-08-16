const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M, V] = stdin[0].split(" ").map(Number);
const arr = stdin.slice(1).map((str) => str.split(" ").map(Number));

function solution(N, M, V, arr) {
  const visited = Array.from({ length: N + 1 }, () => 0);
  const graph = Array.from(Array(N + 1), () => []);

  const dfs_path = [];
  const bfs_path = [];

  function DFS(v) {
    dfs_path.push(v);

    for (let i = 0; i < graph[v].length; ++i) {
      const next = graph[v][i];
      if (visited[next]) continue;

      visited[next] = 1;
      DFS(next);
    }
  }

  function BFS(v) {
    const q = [];
    q.push([v, 0]);
    visited[v] = 1;

    while (q.length) {
      const [node, cnt] = q.shift();

      bfs_path.push(node);

      for (let i = 0; i < graph[node].length; ++i) {
        const next = graph[node][i];

        if (visited[next]) continue;

        visited[next] = 1;
        q.push([next, cnt + 1]);
      }
    }
  }

  arr.forEach((item) => {
    const [u, w] = item;

    graph[u].push(w);
    graph[w].push(u);
  });

  graph.forEach((item) => item.sort((a, b) => a - b));

  visited[V] = 1;
  DFS(V);
  visited.fill(0);
  BFS(V);

  console.log(dfs_path.join(" "));
  console.log(bfs_path.join(" "));
}

solution(N, M, V, arr);
