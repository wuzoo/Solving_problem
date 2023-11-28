function solution(targets) {
  let answer = 0;

  let [s, e] = [-1, 100000000];
  targets
    .sort((a, b) => a[0] - b[0])
    .map((target) => {
      let [start, end] = target;

      if (start >= s && end <= e) {
        [s, e] = [start, end];
      } else if (start < e && end > e) {
        [s, e] = [start, e];
      } else {
        answer++;
        [s, e] = [start, end];
      }
    });

  return answer + 1;
}
