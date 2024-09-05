function solution(n, edge) {
  const graph = Array.from(Array(n + 1), () => []);
  const distance = Array.from({ length: n + 1 }, () => Infinity);
  distance[0] = -1;

  edge.forEach((item) => {
    const [a, b] = item;
    graph[a].push(b);
    graph[b].push(a);
  });

  const q = [];
  q.push([1, 0]);
  distance[1] = 0;

  while (q.length) {
    const [current, cost] = q.shift();

    for (let i = 0; i < graph[current].length; ++i) {
      const next = graph[current][i];
      const dist = cost + 1;

      if (dist > distance[next]) continue;

      if (dist < distance[next]) {
        q.push([next, dist]);
        q.sort((a, b) => a[1] - b[1]);
        distance[next] = dist;
      }
    }
  }
  const maxDistance = Math.max(...distance);

  return distance.slice(1).filter((item) => item === maxDistance).length;
}
