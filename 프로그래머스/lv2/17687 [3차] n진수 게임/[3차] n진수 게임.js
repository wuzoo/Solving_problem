function solution(n, t, m, p) {
  var answer = "";
  let tmp = "";

  for (let i = 0; i < t * m; ++i) {
    tmp += i.toString(n);
  }

  for (let i = p - 1; answer.length < t; i += m) {
    answer += tmp[i].toString(n).toUpperCase();
  }

  return answer;
}
