function solution(answers) {
  var answer = [];
  let score = [];

  let one = [1, 2, 3, 4, 5];
  let two = [2, 1, 2, 3, 2, 4, 2, 5];
  let three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

  let iter = 1;
  while (iter < 4) {
    if (iter === 1) {
      score.push(answers.filter((v, i) => v === one[i % 5]).length);
    }
    if (iter === 2) {
      score.push(answers.filter((v, i) => v === two[i % 8]).length);
    }
    if (iter === 3) {
      score.push(answers.filter((v, i) => v === three[i % 10]).length);
    }
    ++iter;
  }
  let mx = Math.max(...score);
  score.forEach((item, idx) => {
    if (mx === item) {
      answer.push(idx + 1);
    }
  });
  return answer;
}
