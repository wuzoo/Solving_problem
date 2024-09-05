function solution(n) {
  let cnt = 1;
  for (let i = 1; i <= n / 2; ++i) {
    let sum = 0;
    let k = i;

    while (sum < n) {
      sum += k;
      k += 1;
    }
    if (sum === n) {
      cnt++;
    }
  }

  return cnt;
}
