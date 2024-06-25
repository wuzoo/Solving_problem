function solution(n, times) {
  times.sort((a, b) => a - b);

  let st = 1;
  let en = times.at(-1) * n;
  while (st < en) {
    const mid = Math.floor((st + en) / 2);
    const sum = times.reduce((acc, cur) => acc + Math.floor(mid / cur), 0);

    if (sum >= n) {
      en = mid;
    } else {
      st = mid + 1;
    }
  }

  return st;
}
