function solution(numbers, target) {
  const visited = new Array(numbers.length).fill(0);

  const dx = [1, -1];
  let cnt = 0;
  function DFS(k, count) {
    if (count === numbers.length) {
      if (k === target) {
        cnt++;
      }
      return;
    }
    for (let i = 0; i < 2; ++i) {
      DFS(k + dx[i] * numbers[count], count + 1);
    }
  }

  DFS(0, 0);

  return cnt;
}
