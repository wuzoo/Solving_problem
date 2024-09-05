function solution(x, y, n) {
  let answer = -1;
  const q = [[y, 0]];

  while (q.length !== 0) {
    const [y, cnt] = q.shift();

    if (y === x) {
      answer = cnt;
      break;
    }

    if (y % 2 === 0) {
      q.push([y / 2, cnt + 1]);
    }
    if (y % 3 === 0) {
      q.push([y / 3, cnt + 1]);
    }
    if (y - n >= x) {
      q.push([y - n, cnt + 1]);
    }
  }

  return answer;
}
