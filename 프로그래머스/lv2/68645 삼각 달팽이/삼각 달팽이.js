function solution(n) {
  const arr = Array.from(Array(n), (_, i) => Array(i + 1).fill(0));

  let idx1 = -1;
  let idx2 = 0;
  let number = 0;

  for (let i = n; i > 0; i -= 3) {
    arr[++idx1][idx2] = ++number;

    for (let j = 0; j < i - 1; ++j) arr[++idx1][idx2] = ++number;
    for (let j = 0; j < i - 1; ++j) arr[idx1][++idx2] = ++number;
    for (let j = 0; j < i - 2; ++j) arr[--idx1][--idx2] = ++number;
  }

  return arr.flat();
}
