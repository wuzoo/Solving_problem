function solution(n, computers) {
  const visited = Array(n).fill(0);

  function DFS(vertex) {
    for (let i = 0; i < computers[vertex].length; ++i) {
      if (computers[vertex][i] === 1 && i !== vertex) {
        if (visited[i]) continue;
        visited[i] = 1;
        DFS(i);
      }
    }
  }

  let cnt = 0;
  for (let i = 0; i < n; ++i) {
    if (visited[i]) continue;
    cnt++;
    DFS(i);
  }

  return cnt;
}
