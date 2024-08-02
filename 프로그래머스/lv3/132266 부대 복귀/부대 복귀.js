function solution(n, roads, sources, destination) {
  const answer = [];

  const graph = Array.from(Array(n + 1), () => []);
  const d = Array.from(Array(n + 1), () => Infinity);

  roads.forEach((item) => {
    const [a, b] = item;

    graph[b].push([a, 1]);
    graph[a].push([b, 1]);
  });

  const q = [[destination, 0]];
  d[destination] = 0;

  while (q.length) {
    const [curNode, curCost] = q.shift();

    if (d[curNode] < curCost) continue;

    for (const v of graph[curNode]) {
      const node = v[0];
      const dist = curCost + v[1];

      if (dist < d[node]) {
        q.push([node, dist]);
        d[node] = dist;
      }
    }
  }

  sources.forEach((item) => {
    if (item === destination) answer.push(0);
    else answer.push(Number.isFinite(d[item]) ? d[item] : -1);
  });

  return answer;
}
