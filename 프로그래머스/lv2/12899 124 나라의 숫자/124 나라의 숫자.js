function solution(n) {
  const answer = [];

  while (n > 3) {
    if (n % 3 === 0) {
      answer.push(4);
      n = n / 3 - 1;
    } else {
      answer.push(n % 3);
      n = Math.floor(n / 3);
    }
  }
  answer.push(n % 3 === 0 ? 4 : n % 3);

  return answer.reverse().join("");
}
