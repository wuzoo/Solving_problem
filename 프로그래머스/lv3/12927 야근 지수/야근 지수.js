function solution(n, works) {
  works.sort((a, b) => b - a);

  while (n) {
    const max = works[0];
    const maxCnt = works.filter((item) => item === max).length;

    if (n > maxCnt) {
      n -= maxCnt;
      for (let i = 0; i < maxCnt; ++i) {
        works[i]--;
      }
    } else {
      for (let i = 0; i < n; ++i) {
        works[i]--;
      }
      break;
    }

    if (works.filter((item) => item !== 0).length === 0) break;
    works.sort((a, b) => b - a);
  }

  return works.reduce((acc, cur) => acc + cur ** 2, 0);
}
