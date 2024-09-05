function solution(n, edge) {
  var answer = 0;

  const graph = Array.from(Array(n + 1), () => []);
  const visited = new Array(n + 1).fill(0);
  const reach = new Array(n + 1).fill(0);

  edge.forEach((item) => {
    const [a, b] = item;

    graph[a].push(b);
    graph[b].push(a);
  });

  const q = [];
  q.push([1, 0]);
  visited[1] = 1;

  while (q.length) {
    const [vertex, cnt] = q.shift();
    reach[vertex] = cnt;

    for (let i = 0; i < graph[vertex].length; ++i) {
      const next = graph[vertex][i];
      if (!visited[next]) {
        visited[next] = 1;
        q.push([next, cnt + 1]);
      }
    }
  }
  const maxReach = Math.max(...reach);

  return reach.filter((item) => item === maxReach).length;
}
