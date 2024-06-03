function solution(n, s) {
  var answer = [];

  if (n > s) return [-1];

  const quote = Math.floor(s / n);
  const mod = s % n;

  while (n--) {
    answer.push(quote);
  }

  let idx = 0;
  let t = mod;

  while (t--) {
    answer[idx++]++;
  }

  answer.sort((a, b) => a - b);

  return answer;
}
