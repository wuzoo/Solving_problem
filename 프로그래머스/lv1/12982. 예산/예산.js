function solution(d, budget) {
  var answer = 0;

  d.sort((a, b) => a - b).forEach((item) => {
    if (budget < item) {
      return;
    }
    answer++;
    budget -= item;
  });

  return answer;
}
