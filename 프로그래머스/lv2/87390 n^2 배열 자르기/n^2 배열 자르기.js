function solution(n, left, right) {
  var answer = [];

  while (left <= right) {
    const row = Math.floor(left / n) + 1;
    const column = (left % n) + 1;

    const value = Math.max(row, column);

    answer.push(value);
    left++;
  }

  return answer;
}
