function solution(n, stations, w) {
  var answer = 0;
  const iterSize = 2 * w + 1;

  let current = 1;
  let idx = 0;
  while (idx < stations.length) {
    if (current < stations[idx] - w && current) {
      answer += Math.ceil((stations[idx] - w - current) / iterSize);
      current = stations[idx] + w + 1;
      idx++;
      continue;
    }
    current = stations[idx] + w + 1;
    idx++;
  }
  if (current <= n) answer += Math.ceil((n - current || 1) / iterSize);

  return answer;
}
