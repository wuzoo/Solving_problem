function solution(k, score) {
  var answer = [];
  let sorted = [];
  score.map((item) => {
    sorted.push(item);
    let arr = sorted.sort((a, b) => b - a);
    arr.length === k + 1 && arr.pop();
    answer.push(sorted[sorted.length - 1]);
  });

  return answer;
}
