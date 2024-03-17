function solution(queue1, queue2) {
  var answer = 0;

  const tmp1 = [...queue1],
    tmp2 = [...queue2];

  let sum1 = tmp1.reduce((acc, cur) => acc + cur, 0);
  let sum2 = tmp2.reduce((acc, cur) => acc + cur, 0);

  let idx1 = 0,
    idx2 = 0;
  while (sum1 !== sum2) {
    if (idx1 >= queue1.length && idx2 >= queue2.length) {
      answer = -1;
      break;
    }
    if (sum1 > sum2) {
      tmp2.push(tmp1[idx1]);
      sum1 -= tmp1[idx1];
      sum2 += tmp1[idx1];
      idx1++;
    } else {
      tmp1.push(tmp2[idx2]);
      sum2 -= tmp2[idx2];
      sum1 += tmp2[idx2];
      idx2++;
    }
    answer++;
  }

  return answer;
}
