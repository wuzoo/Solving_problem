function solution(n, s, a, b, fares) {
  var answer = 0;

  const graph = Array.from(Array(n + 1), () => []);
  let ds = Array.from(Array(n + 1), () => Infinity);
  let da = Array.from(Array(n + 1), () => Infinity);
  let db = Array.from(Array(n + 1), () => Infinity);
  const totalDistance = [];

  function Dijkstra(q, d) {
    while (q.length) {
      const [currentNode, cost] = q.shift();

      if (d[currentNode] < cost) continue;

      for (let i = 0; i < graph[currentNode].length; ++i) {
        const [n, c] = graph[currentNode][i];

        const dist = c + cost;

        if (dist < d[n]) {
          q.push([n, dist]);
          q.sort((a, b) => a[1] - b[1]);
          d[n] = dist;
        }
      }
    }
    return d;
  }

  fares.forEach((item) => {
    const [u, v, w] = item;
    graph[u].push([v, w]);
    graph[v].push([u, w]);
  });

  const q = [[s, 0]];
  ds[s] = 0;
  ds = Dijkstra(q, ds);

  const qa = [[a, 0]];
  da[a] = 0;
  da = Dijkstra(qa, da);

  const qb = [[b, 0]];
  db[b] = 0;
  db = Dijkstra(qb, db);

  for (let i = 1; i < n + 1; ++i) {
    totalDistance.push(ds[i] + da[i] + db[i]);
  }

  const min = Math.min(...totalDistance);
  const newStart = totalDistance.findIndex((item) => item === min) + 1;

  const newQ = [[newStart, 0]];
  let newD = Array.from(Array(n + 1), () => Infinity);
  newD[newStart] = 0;

  newD = Dijkstra(newQ, newD);

  const sum = newD[a] + newD[b];

  return sum + ds[newStart];
}
