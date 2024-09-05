function solution(A, B) {
  var answer = 0;

  A.sort((a, b) => a - b);
  B.sort((a, b) => b - a);

  A.forEach((num, index) => {
    answer += num * B[index];
  });

  return answer;
}
