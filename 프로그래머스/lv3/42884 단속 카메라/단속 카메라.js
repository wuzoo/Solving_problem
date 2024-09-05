function solution(routes) {
  let current = [-30001, 30001];
  const intersections = [];

  routes.sort((a, b) => a[1] - b[1]);

  for (let i = 0; i < routes.length; ++i) {
    const [start, end] = routes[i];

    if (start >= current[0] && end <= current[1]) {
      current[0] = start;
      current[1] = end;
    } else if (start <= current[1] && start >= current[0]) {
      current[0] = start;
    } else if (start > current[1]) {
      intersections.push(current);
      current = [start, end];
    }
  }
  if (JSON.stringify(current) !== JSON.stringify(intersections.at(-1))) {
    intersections.push(current);
  }

  return intersections.length;
}
