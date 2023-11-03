function solution(t, p) {
  var answer = 0;

  for (let i = 0; i <= t.length - p.length; ++i) {
    let arr = t.slice(i, i + p.length);
    if (+arr <= +p) {
      answer++;
    }
  }

  return answer;
}
