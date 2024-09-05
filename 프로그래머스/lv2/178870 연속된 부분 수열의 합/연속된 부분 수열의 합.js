function solution(sequence, k) {
  var answer = [0, 1000000];

  let en = 0;
  let sum = sequence[0];
  for (let st = 0; st < sequence.length; ++st) {
    while (en < sequence.length && sum < k) {
      en++;
      sum += sequence[en];
    }
    if (sum === k) {
      if (answer.length === 0) answer = [st, en];
      else if (answer[1] - answer[0] > en - st) {
        answer = [st, en];
      }
    }
    sum -= sequence[st];
  }

  return answer;
}
