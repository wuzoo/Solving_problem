function solution(n, results) {
  const graph = Array.from(Array(n + 1), () => Array(n + 1).fill(0));

  const arr = new Array(n).fill(0).map((_, i) => i + 1);

  results.forEach((item) => {
    const [A, B] = item;

    graph[A][B] = 1;
  });

  arr.forEach((k) => {
    arr.forEach((i) => {
      arr.forEach((j) => {
        if (i !== j) {
          if (graph[i][k] !== 0 && graph[k][j] !== 0) {
            if (graph[i][j] === 0) {
              graph[i][j] = graph[i][k] + graph[k][j];
            } else {
              graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
            }
          }
        }
      });
    });
  });

  const result = new Array(n + 1).fill(0);
  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= n; ++j) {
      if (i === j) continue;

      if (graph[j][i] !== 0) {
        result[i]++;
      }
    }
  }

  for (let i = 1; i <= n; ++i) {
    result[i] += graph[i].filter((item) => item !== 0).length;
  }

  return result.filter((item) => item === n - 1).length;
}
