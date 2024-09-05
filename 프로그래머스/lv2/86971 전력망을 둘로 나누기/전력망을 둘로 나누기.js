function solution(n, wires) {
  const graph = Array.from(Array(n + 1), () => []);
  const visited = new Array(n + 1);

  wires.forEach(([x, y]) => {
    graph[x].push(y);
    graph[y].push(x);
  });

  function DFS(v, cut) {
    let cnt = 1;
    for (let i = 0; i < graph[v].length; ++i) {
      if (visited[graph[v][i]]) continue;
      if (graph[v][i] === cut) continue;

      visited[graph[v][i]] = 1;
      cnt += DFS(graph[v][i], cut);
    }
    return cnt;
  }

  let min = 101;
  wires.forEach(([x, y]) => {
    visited[x] = 1;
    let first = DFS(x, y);
    visited[y] = 1;
    let second = DFS(y, x);

    min = Math.min(Math.abs(first - second), min);
    visited.fill(0);
  });

  return min;
}
