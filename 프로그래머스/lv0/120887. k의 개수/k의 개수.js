function solution(i, j, k) {
  var answer = 0;

  for (let a = i; a <= j; ++a) {
    const arr = a.toString().split("");
    arr.map((item) => +item === k && answer++);
  }

  return answer;
}
