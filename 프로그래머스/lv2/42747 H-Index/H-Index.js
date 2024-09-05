function solution(citations) {
  const mx = Math.max(...citations);

  let cnt = 0;
  for (let h = 0; h <= mx; ++h) {
    const len = citations.filter((item) => item >= h).length;

    if (citations.length - len <= h && len >= h) {
      if (h > cnt) {
        cnt = h;
      }
    }
  }

  return cnt;
}
